package main

import (
	"fmt"
	"os"
	"path/filepath"
)

// scanDir stands for the directory scanning implementation
func scanDir(dir string) error {
	var files []string
	dirs, symlinks, devices,sockets,other := 0,0,0,0,0
	err := filepath.Walk(dir, func(path string, info os.FileInfo, err error) error{
		files = append(files, info.Name())
		if info.IsDir(){
			dirs++
		}else if info.Mode()&os.ModeSymlink == os.ModeSymlink{
			symlinks++
		}else if info.Mode()&os.ModeDevice == os.ModeDevice{
			devices++
		}else if info.Mode()&os.ModeSocket == os.ModeSocket{
			sockets++
		}else{
			other++
		}
			return nil
	 })
	 
	if err != nil {
        panic(err)
	}
	//fmt.Println(os.ModeSymlink,os.ModeDevice,os.ModeSocket)
	fmt.Println("Directory Scanner Tool")
	fmt.Println("+-------------------------+------+")
	fmt.Println("|Path \t\t\t  |", dir,"|")
	fmt.Println("+-------------------------+------+")
	fmt.Println("|Directories \t\t  |", dirs,"\t |")
	fmt.Println("|Symbolic Links \t  |", symlinks,"\t |")
	fmt.Println("|Devices \t\t  |", devices,"\t |")
	fmt.Println("|Sockets \t\t  |", sockets,"\t |")
	fmt.Println("|Other files \t\t  |", other,"\t |")
	fmt.Println("+-------------------------+------+")

	return nil
}

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage: ./dir-scan <directory>")
		os.Exit(1)
	}

	scanDir(os.Args[1])
}
