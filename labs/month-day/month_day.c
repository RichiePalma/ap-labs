#include <stdio.h>
#include <stdlib.h>

static char *months[13] = {"Illegal Month","Jan","Feb","Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
static int calendar[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leap_calendar[13] = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* month_day function's prototype*/
void month_day(int year, int yearday){
    if(year%4 == 0 && year%100 != 0 || year%400 == 0){
        if(yearday<1||yearday>366){
            printf("%s\n",months[0]);
        }
        else{
            int i = 1;
            while(yearday>leap_calendar[i]){
                yearday -= leap_calendar[i];
                i++;
            }
            printf("%s %i, %i \n",months[i],yearday,year);
        }
    }
    else{
        if(yearday<1||yearday>365){
            printf("%s\n",months[0]);
        }
        else{
            int i = 1;
            while(yearday>calendar[i]){
                yearday -= calendar[i];
                i++;
            }
            printf("%s %i, %i \n",months[i],yearday,year);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3){
        printf("Wrong amount of arguments, it should be: ./file_name year ithday\n");
    }
    int year,yearday;
    year = atoi(argv[1]);
    yearday = atoi(argv[2]);
    month_day(year,yearday);
    return 0;
}
