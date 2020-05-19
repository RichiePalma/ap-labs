/*
Exercise 9.4: Construct a pipeline that connects an arbitrary number of goroutines with channels.
What is the maximum number of pipeline stages you can create without running out of
memory? How long does a value take to transit the entire pipeline?
*/

package main

import (
	"flag"
	"fmt"
	"os"
	"strconv"
	"time"
)

func main() {

	pipes := flag.Int("pipes", 1000000, "number of sequential pipes")
	verbose := flag.Bool("verbose", false, "interactive printing number of created pipes")
	flag.Parse()

	var start time.Time

	ch := make(chan struct{})
	in := ch

	start = time.Now()

	for i := 1; i <= *pipes; i++ {
		out := make(chan struct{})

		go func(in <-chan struct{}, out chan<- struct{}, i int) {
			out <- <-in
		}(in, out, i)

		in = out
		if *verbose {
			fmt.Printf("\r[%d] ", i)
		}
	}
	if *verbose {
		fmt.Println()
	}
	fmt.Printf("10000000 pipes broke my laptop, testing with 100000.\n")
	fmt.Printf("1000000 Goroutines created in %v\n", time.Since(start))
	start = time.Now()
	ch <- struct{}{}
	<-in
	fmt.Printf("How long does a value take to transit the entire pipeline? %v\n", time.Since(start))

	report, err := os.Create("Report9-4.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	tme := time.Since(start)
	str := "What is the maximum number of pipeline stages you can create without running out of memory?  " + strconv.Itoa(*pipes) + "\nHow long does a value take to transit the entire pipeline? " + tme.String()
	_, err = report.WriteString(str)
	if err != nil {
		fmt.Println(err)
		report.Close()
		return
	}
	fmt.Println("Report stored in Report9-4.txt\n")
}
