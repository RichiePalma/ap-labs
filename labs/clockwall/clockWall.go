package main

import (
        "io"
        "log"
        "net"
        "os"
        "sync"
        "strings"
        "bytes"
		"fmt"
)

var wg sync.WaitGroup

func mustCopy(dst io.Writer, src io.Reader, city string) {
		defer wg.Done()
		for{
			cityBuf := bytes.NewBufferString(city)
			
			_, err := io.CopyN(cityBuf,src, 9)
			if err != nil {
				log.Fatal(err)
				return;
			}
			fmt.Printf("%s", cityBuf.String())
		}
}

func main(){
	
		wg.Add(len(os.Args)-1)
		for i := 1; i < len(os.Args); i++{ 
			s := strings.Split(os.Args[i], "=")
			city, port := s[0] + "\t: \t", s[1]
			
			conn, err := net.Dial("tcp", port)
			
			if err != nil {
					log.Fatal(err)
			}
			defer conn.Close()
			go mustCopy(os.Stdout, conn, city)
		}
		wg.Wait()
}