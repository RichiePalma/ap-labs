#include <stdio.h>
#include <stdlib.h>  

// #define   LOWER  0       /* lower limit of table */
// #define   UPPER  300     /* upper limit */
// #define   STEP   20      /* step size */

/* print Fahrenheit-Celsius table */

int main(int argc, char **argv)

{
    char *p;
    int fahr;
    // printf("%i", argc);
    if(argc == 2){
        fahr = strtol(argv[1], &p, 10);
        printf("Fahrenheit: %3d, Celcius: %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
    else{
        int step = strtol(argv[3], &p, 10);
    
        for (fahr = strtol(argv[1], &p, 10); fahr <= strtol(argv[2], &p, 10); 
            fahr = fahr + step)
	    printf("Fahrenheit: %3d, Celcius: %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    } 
    return 0;
}
