// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 156.

// Package geometry defines simple types for plane geometry.
//!+point
package main

import (
	"math"
	"fmt"
	"math/rand"
	"time"
	"os"
	"strconv"
)

type Point struct{ X, Y float64 }

// traditional function
func Distance(p, q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

// same thing, but as a method of the Point type
func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

//!-point

//!+path

// A Path is a journey connecting the points with straight lines.
type Path []Point

func RandCoord(min int,max int) float64 {
	rand.Seed(time.Now().UTC().UnixNano())
	//return math.Round(rand.Float64()*float64((max-min) + min)/10)
	return rand.Float64()*float64((max-min) + min)
}

func genVertices(sides int) Path {
	v := make(Path,sides)
	fmt.Printf("- Generating a [%d] sides figure\n",sides)
	fmt.Println("- Figure's vertices")
	for i:= 0; i < sides; i++ {
		x := RandCoord(-100,100)
		y := RandCoord(-100,100)
		fmt.Printf("\t- (  %f,  %f)\n",x,y)
		v[i] = Point{x,y}
	}
	return v
}

// Distance returns the distance traveled along the path.
func (path Path) Distance() float64 {
	sum := 0.0
	dist := 0.0
	fmt.Println("- Figure's Perimeter")
	for i := range path {
		if i == 1{
			dist = path[i-1].Distance(path[i])
			sum += dist
			fmt.Printf("\t- %f", dist)
		}else if i > 1 {
			dist = path[i-1].Distance(path[i])
			sum += dist
			fmt.Printf("+ %f",dist)
		}
	}
	dist = path[len(path)-1].Distance(path[0])
	sum += dist // Last path, assuming figure is closed
	fmt.Printf("+ %f = %f\n",dist,sum)
	return sum
}

func main(){
	if len(os.Args) != 2{
		fmt.Println("Wrong run format: ./geometry {sides}")
		os.Exit(2)
	}

	sides, _:= strconv.Atoi(os.Args[1])
	if sides < 3{
		fmt.Println("Sides should be above 2")
	}else{
		p := genVertices(sides)
		p.Distance()
	}
}
//!-path
