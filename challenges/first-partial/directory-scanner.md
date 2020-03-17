Directory Scanner
=================
Implement a directory scanner tool for any given path. It's highly recommended to implement it for a UNIX-based machine.

Requirements
------------
- The program must be implemented in Golang programming language.
- Given one path, the program must count the following file's types:
  - Directories
  - Symbolic Links
  - Devices
  - Sockets
  - Others
- Use the provided template `dir-scan.go`
- In some system's paths, you may run your program as super user (root).
- You need to follow the output format guidelines. Extra characters or improper error handling will be penalized in the project's grade.
- Coding best practices that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.


Sample Execution and output
---------------------------

You can run the `Makefile` to build the go source code or to remove the binary.

```
# Compiles both the go and c source codes
make

# Removes both the go and c binaries
make clean 

# go build -o directory-scanner dir-scan.go 
make go

# rm -rf directory-scanner
make rm-go
```

You could also use the `go run` command, but it is better to build the binary for one to be able to execute it as root. 

```
$ ./directory-scanner /tmp
Directory Scanner Tool
+-------------------------+------+
| Path                    | /tmp |
+-------------------------+------+
| Directories             | 10   |
| Symbolic Links          | 5    |
| Devices                 | 11   |
| Sockets                 | 2    |
| Symbolic Links          | 5    |
| Other files             | 50   |
+-------------------------+------+
```

Test Cases
----------
The program will be tested with the following paths:

1. `/tmp` directory
```
$ ./directory-scanner /tmp
```

2. `/etc` directory
```
$ ./directory-scanner /etc
```

3. `/usr/lib` directory
```
$ ./directory-scanner /usr/lib
```

4. `/dev` directory
```
$ ./directory-scanner /dev
```

Useful links
------------
- https://golang.org/pkg/os/#Lstat
- https://golang.org/pkg/path/filepath/#Walk