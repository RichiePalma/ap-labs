Lab - Word Reverser
===================
Using basic concepts of C Programming from [C Basics lecture](http://talks.obedmr.com/hello-c-world/00-basics.slide#1),
create a program that reads input from console with `getchar()` function.

Every word will be automatically reversed and printed when the `enter` key is pressed.

The condition to stop your program will be the `EOF` char, also triggered by `Cntrl-D`.

How to run
-----------
Compile reverser.c 
```
# make will create the binary reverser
# This runs: gcc reverser.c -o reverser

make
```
Then you can run the binary
```
# ./reverser <any arg is ignored>
# Ctrl + D to end excecution 
# Press twice if current line isn't empty
# It will also stop if line is empty
./reverser 
This should be reversed
desrever eb dluohs sihT
What about this?
?siht tuoba tahW
```
You can delete the binary with
```
make clean
```

General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Submit your code to your personal fork.
3. Use the  `reverser.c` file for your code.
4. Have fun and don't forget the next section.


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)