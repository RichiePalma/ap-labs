#include <stdio.h>
#define LINE_LENGTH 500

void reverse(char line[],int len){
    int i;
    char temp;

    for(i = 0; i<len/2;i++){
        temp = line[i];
        line[i] = line[len -i -1];
        line[len -i -1] = temp;
    }
}

int readLines(char str[], int limit) {
  int i, c;
  for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; ++i){
    str[i] = c;
  }
  str[i] = '\0';
  return i;
}

int main(){
    int len;
    char line[LINE_LENGTH];
    while ((len = readLines(line, LINE_LENGTH)) > 0) {
        reverse(line,len);
        printf("%s\n", line);
    }
    return 0;
}