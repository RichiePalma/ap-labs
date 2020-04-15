#include <stdio.h>
#include <stdlib.h>

int infof(const char *format, ...);
int warnf(const char *format, ...);
int errorf(const char *format, ...);
int panicf(const char *format, ...);

int main() {
    infof("This text should have info color\n");
    warnf("Warnings may have different %s\n","color");
	errorf("bright colors will call your attention to this mistake\n");
	panicf("something is %s, %s with %s\n","wrong","proceed","caution");
    return 0;
}