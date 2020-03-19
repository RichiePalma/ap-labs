Lab - mycat
===========

Rewrite the `cat2.c` program by using `read`, `write`, `open` and `close` instead of their library equivalents.

Then, generate a report with performance metrics between the existing `cat` command  and your `mycat`.
The format of the report is free, you can add charts or whatever helps to understand the speed of both approaches.

General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. Use the [`cat2.c`](./cat2.c) file for your code.
4. Have fun and don't forget the [next section](#how-to-submit-your-work).

How to run
----------

Run the makefile to either compile both c files or delete the binaries generated.

```
# Compiles cat2.c and fcat2.c
make

# Deletes cat2 and fcat2 binaries
make clean
```

Report
------

I decided to keep the original cat2 that was forked from the [CodersSquad repo](https://github.com/CodersSquad/ap-labs/blob/master/labs/mycat/cat2.c) and rename it `fcat2.c` for it to be compared with `cat2.c` and Linux's `cat`.

As sample, a long text was [retrieved](https://whiletrue.neocities.org/lte.html) and saved as `TheLongestTextEver.txt`.

Then tested each `cat` by using the `bench` [utility benchmark](https://www.ostechnix.com/how-to-benchmark-linux-commands-and-programs-from-commandline/) which uses [Haskell's criterion library](https://hackage.haskell.org/package/criterion). Running this `bench` command gives the following output on my machine:

```
bench 'cat TheLongestTextEver.txt' './cat2 TheLongestTextEver.txt' './fcat2 TheLongestTextEver.txt'
benchmarking bench/cat TheLongestTextEver.txt
time                 1.936 ms   (1.898 ms .. 1.998 ms)
                     0.992 R²   (0.987 R² .. 0.998 R²)
mean                 1.924 ms   (1.900 ms .. 1.963 ms)
std dev              100.2 μs   (69.15 μs .. 135.7 μs)
variance introduced by outliers: 37% (moderately inflated)

benchmarking bench/./cat2 TheLongestTextEver.txt
time                 1.783 ms   (1.763 ms .. 1.807 ms)
                     0.999 R²   (0.998 R² .. 1.000 R²)
mean                 1.741 ms   (1.729 ms .. 1.755 ms)
std dev              43.65 μs   (35.04 μs .. 59.38 μs)
variance introduced by outliers: 13% (moderately inflated)

benchmarking bench/./fcat2 TheLongestTextEver.txt
time                 2.737 ms   (2.710 ms .. 2.765 ms)
                     0.999 R²   (0.998 R² .. 1.000 R²)
mean                 2.760 ms   (2.738 ms .. 2.787 ms)
std dev              74.63 μs   (59.90 μs .. 106.3 μs)
variance introduced by outliers: 13% (moderately inflated)
```
From this output one can conclude that `cat2` is slightly faster than Linux's `cat` and even faster than `fcat2`. This is because the latest implements C standard functions like ```fopen()``` in contrast to `cat2` which implements syscalls like `open()`.  

How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)