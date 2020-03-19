
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc,char *argv[]){
    char buffer [BUFF_SIZE];
    int fr;
    int fd = open(argv[1],O_RDONLY);
    
    if (fd ==-1) { 
        perror("Error reading file");
        exit(1); 
    } 
    buffer[BUFF_SIZE] ='\0';
    while (fr = read(fd,buffer,BUFF_SIZE)){
        write(1,buffer,fr); //Write into fd = 1 (Console) what is in buffer up to BUFF_SIZE bytes
    }
    printf("\n");
   

    if (close(fd) < 0){
        perror("Error closing file");
        exit(1); 
    }

    return 0;
}