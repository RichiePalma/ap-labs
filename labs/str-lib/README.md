Lab - String Manipulation Library
=================================

- Implement a library for string manipulation library with the following functions:
```
int mystrlen(char *str)
char *mystradd(char *origin, char *addition)
int mystrfind(char *origin, char *substr)
```

- Call all functions on `strlib.c` from the `main.c` file

- Your program needs to support the following arguments. Check the expected output:
```
$ ./main originalVeryLongString Addition Add
Initial Lenght      : 22
New String          : originalVeryLongStringAddition
SubString was found : yes
```

How to compile
---

You can compile by running the Makefile which will link both c files into one binary. The parameter clean will delete such binary. 

```
# gcc main.c strlib.c -o main
make

# rm -rf main
make clean
```

Note that an extra instruction was given during class. If the substring is found, the output has to indicate the position were the substring starts. Such position varies from 0 to NewStringLength-1. If the substring is found twice or more, it will only return the position of the first occurrence. 

General instructions and advices
--------------------------------
0. Take a look on [Linking Process in C](http://talks.obedmr.com/hello-c-world/03-linking.slide#1) for a better undersanding.
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. Use the  `strlib.c` and `main.c` files for your code.
4. Have fun and don't forget the following section.


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)