// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 254.
//!+

// Chat is a server that lets clients chat with each other.
package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"net"
	"os"
	"regexp"
	"strings"
	"time"
)

//!+broadcaster
type client chan<- string // an outgoing message channel

var (
	entering = make(chan client)
	leaving  = make(chan client)
	messages = make(chan string) // all incoming client messages
	chat = make(map[string]net.Conn) // Here is the connection for the user
)

type user struct {
	username string
	role string
}

func getRole(username string) string{
	for _, n := range users {
		if n.username == "<user>"+username{
			return n.role
		}
	}
	return "N/A"
}

func inChat(username string) bool {
	for _, n := range users {
		if n.username == "<user>"+username{
			return true
		}
	}
	return false
}

var users []user

func broadcaster() {
	clients := make(map[client]bool) // all connected clients
	for {
		select {
		case msg := <-messages:
			// Broadcast incoming message to all
			// clients' outgoing message channels.
			for cli := range clients {
				cli <- msg
			}
		case cli := <-entering:
			clients[cli] = true
		case cli := <-leaving:
			delete(clients, cli)
			close(cli)
		}
	}
}

//!-broadcaster

//!+handleConn
func handleConn(conn net.Conn) {
	ch := make(chan string) // outgoing client messages
	who := ""
	go clientWriter(conn, ch)
	input := bufio.NewScanner(conn)
	for input.Scan() {
		mssg := input.Text()

		if match, _ := regexp.MatchString("<user>.+", mssg); match {
			newUser := user{username: mssg, role: "user"}
			if len(users) == 0 {
				newUser = user{username: mssg, role: "admin"}
			}
			users = append(users, newUser)
			// check if the user is already select
			separatedString := strings.Split(mssg, ">")
			who = separatedString[1]
			fmt.Printf("irc-server > New connected user [%s] \n", who)
			ch <- "irc-server > Welcome to the simple IRC server"
			ch <- "irc-server > Your user [" + who + "] is successfully logged"
			if newUser.role == "admin" {
				ch <- "irc-server > Congrats, you were the first user."
				ch <- "irc-server > You're the new IRC Server ADMIN"
				fmt.Printf("irc-server > [%s] was promoted as the channel ADMIN\n", who)
			}
			messages <- "irc-server > New connected user [" + who + "]"
			entering <- ch
			chat[who] = conn
		} else if mssg == "/users" { // User list
			fmt.Fprintf(conn, "irc-server > ")
			for key := range chat {
				fmt.Fprintf(conn, "%s, ", key)
			}
			fmt.Fprintf(conn, "\n")
		} else if match, _ := regexp.MatchString("^/msg .+ .+", mssg); match { 
			args := strings.Split(mssg, " ")
			lenSlice := len(args)
			if user, check := chat[args[1]]; check {
				fmt.Fprintf(user, "%s (Only you) > ", who)
				for i := 2; i < lenSlice; i++ {
					fmt.Fprintf(user, " %s ", args[i])
				}
				fmt.Fprintf(user, "\n")
			} else {
				fmt.Fprintf(conn, "irc-server > No user [%s] found, use /users to see connected users. \n", args[1])
			}
		} else if mssg == "/time" { 
			fmt.Fprintf(conn,"irc-server (Only you) > Local Time: America/Mexico_City %s\n",time.Now().Format("15:04"))
		} else if match, _ := regexp.MatchString("^/user .+$", mssg); match { 
			args := strings.Split(mssg, " ")
			if user, check := chat[args[1]]; check {
				fmt.Fprintf(conn, "irc-server > username: %s, IP: %s \n", args[1], user.RemoteAddr().String())
			} else {
				fmt.Fprintf(conn, "irc-server > No user (%s) found, use /users to see connected users. \n", args[1])
			}
		} else if match, _ := regexp.MatchString("^/kick .+$", mssg); match { 
			args := strings.Split(mssg, " ")
			kickedUser := args[1]
			if(getRole(who) == "admin"){
				if private, check := chat[args[1]]; check {
					fmt.Fprintf(private, "irc-server > You're kicked from this channel\n")
					fmt.Fprintf(private, "irc-server > Bad language is not allowed on this channel\n")
				}

				if inChat(kickedUser){
					chat[kickedUser].Close()
					delete(chat, kickedUser)
					fmt.Printf("irc-server > [%s] was kicked\n", kickedUser)
					messages <- "irc-server > [" + kickedUser + "] was kicked from channel for bad language policy violation"
				}else{
					fmt.Fprintf(conn, "irc-server > User [%s] is not part of chat, cannot be kicked\n", kickedUser)
				}

			}else{
				ch <- "irc-server > only channel ADMIN can do this"
			}
		} else {
			messages <- who + "> " + input.Text()
		}
	}
	// NOTE: ignoring potential errors from input.Err()
	leaving <- ch
	messages <- "irc-server > [" + who + "] has left"
	fmt.Printf("irc-server > [%s] left \n", who)
	conn.Close()
}

func clientWriter(conn net.Conn, ch <-chan string) {
	for msg := range ch {
		fmt.Fprintln(conn, msg) // NOTE: ignoring network errors
	}
}

//!-handleConn

//!+main
func main() {
	if(len(os.Args) < 5){
		fmt.Println("Run as following: go run server.go -host <ip> -port <port>")
		os.Exit(2)
	}
	host := flag.String("host", os.Args[2], "host string")
	port := flag.String("port", os.Args[4], "port string")
	flag.Parse()
	fmt.Printf("irc-server > Simple IRC Server started at %s:%s \n", *host, *port)
	fmt.Printf("irc-server > Ready for receiving new clients \n")
	listener, err := net.Listen("tcp", *host+":"+*port)
	if err != nil {
		log.Fatal(err)
	}
	go broadcaster()
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}

//!-main