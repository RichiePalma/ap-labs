#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <regex.h>

#define REPORT_FILE "packages_report.txt"
#define BUFF_SIZE 1024

void analizeLog(char *logFile, char *report);

int main(int argc, char **argv) {

    if (argc < 2) {
	printf("Usage:./pacman-analizer.o pacman.log\n");
	return 1;
    }

    analizeLog(argv[1], REPORT_FILE);

    return 0;
}

void analizeLog(char *logFile, char *report) {
    char buffer [BUFF_SIZE];
    int fr;
    int fd = open(logFile,O_RDONLY);
    int fw = open(report,O_CREAT | O_RDWR | O_TRUNC, 0664);
    char * regexDate = "[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}";
    char * regexInstall = "\[ALPM\] installed";
    char * regexUpgrade = "\[ALPM\] upgraded";
    char * regexRemove = "\[ALPM\] removed";
    
    printf("Generating Report from: [%s] log file\n", logFile);
    
    if (fd ==-1 || fw == -1) { 
        perror("Error opening file");
        exit(1); 
    } 
    //buffer[BUFF_SIZE] ='\0';
    while (fr = read(fd,buffer,BUFF_SIZE)){
        //printf("%s||",buffer);
        //write(1,buffer,fr); 
        write(fw,buffer,fr);
    }
    printf("\n");
   

    if (close(fd) < 0 || close(fw) < 0){
        perror("Error closing file");
        exit(1); 
    }


    printf("Report is generated at: [%s]\n", report);
}
