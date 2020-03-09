Lab - Generic Merge Sort
========================
On this lab you will be creating a [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort) based program for sorting either strings or integers.

As a guide, take a look in the Quick Sort example from the [C Programming Language](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628) book
on **Section 5.11 - Pointers to Functions**.

General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Submit your code to your personal fork.
3. Use the  `generic_merge_sort.c` file for your code.
4. Have fun and don't forget the next section.

How to run
---

Run make to compile

```
# gcc -w generic_merge_sort.c -o generic_merge_sort
make
```

The file sorts 3 arrays, the first one is the arguments it receives when running the binary. The other two are predefined within the code, one of numbers and another one of names. If no argument is given, it will print an empty array and a sorted empty array. 

```
./generic_merge_sort sort this words please
Unsorted: sort this words please 
Sorted: please sort this words 

Unsorted: 234 125 1137 0 10 92 10 92 242 87 45 
Sorted: 0 10 10 45 87 92 92 125 234 242 1137 

Unsorted: Partida Humberto Cesar Ricardo Hector Juan 
Sorted: Cesar Hector Humberto Juan Partida Ricardo 
```


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)