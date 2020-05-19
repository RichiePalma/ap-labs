/*
Exercise 9.5: Write a program with two goroutines that send messages back and forth over
two unbuffered channels in ping-pong fashion. How many communications per second can
the program sustain?
*/

package main

import (
	"fmt"
	"os"
	"strconv"
	"time"
)

var i int
var seconds int

func main() {
	ch1 := make(chan struct{})
	ch2 := make(chan struct{})
	ch3 := make(chan struct{})

	str := "How many communications per second can the program sustain?\n"

	go func() {
		ticker := time.NewTicker(1 * time.Second)
		i = 0
		seconds := 0
		fmt.Println("Number of communications per second:")
	loop:
		for {
			ch1 <- struct{}{}
			select {
			case <-ch2:
				i++
			case <-ticker.C:
				seconds++
				<-ch2
				i++
				fmt.Printf("\r %dth second: %d", seconds, 2*i/seconds)
				str += strconv.Itoa(seconds) + "th second: " + strconv.Itoa(2*i/seconds) + "\n"
				if seconds >= 6 {
					ticker.Stop()
					break loop
				}
			}
		}

		ch3 <- struct{}{}
	}()

	go func() {
		for {
			<-ch1
			ch2 <- struct{}{}
		}
	}()
	<-ch3
	fmt.Println()

	report, err := os.Create("Report9-5.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	str += "Total messages sent: " + strconv.Itoa(i)
	fmt.Println(str)
	_, err = report.WriteString(str)
	if err != nil {
		fmt.Println(err)
		report.Close()
		return
	}
	fmt.Println("Report stored in Report9-5.txt\n")
}
