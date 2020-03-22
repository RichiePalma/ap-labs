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

# Delete binary
make clean
```

The c file sorts the arguments given. Such arguments could be Strings or Integers. If both integers and strings are passed, the MergeSort will sort the integers first then the strings.

```
# Strings only
./generic_merge_sort sort this words please
Unsorted: sort this words please 
Sorted: please sort this words 

# Integers only
./generic_merge_sort 1 4 2 5 3
Unsorted: 1 4 2 5 3 
Sorted: 1 2 3 4 5 

# Both strings and integers
./generic_merge_sort sort this words please 1 4 2 5 3 
Unsorted: sort this words please 1 4 2 5 3 
Sorted: 1 2 3 4 5 please sort this words 
```


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)