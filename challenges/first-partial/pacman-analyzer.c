#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define REPORT_FILE "packages_report.txt"
#define NUM_PACKAGES 1000
#define SIZE_CHAR 50
#define LINE_LENGHT 100

#define BUFF_SIZE 1024
struct package
{
    char *name;
    char *timeInstall;
    char *timeUpgrade;
    int upgrades;
    char *timeRemove;
};

struct package packages[NUM_PACKAGES];

void analizeLog(char *logFile, char *report);

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Usage:./pacman-analizer.o pacman.log\n");
        return 1;
    }

    analizeLog(argv[1], REPORT_FILE);

    return 0;
}

void analizeLog(char *logFile, char *report)
{
    printf("Generating Report from: [%s] log file\n", logFile);
    // Implement your solution here.
    int j;
    char markup[50];
    for (j = 0; j < NUM_PACKAGES; ++j)
    {
        packages[j].name = malloc(sizeof(char) * SIZE_CHAR);
        packages[j].timeInstall = malloc(sizeof(char) * SIZE_CHAR);
        packages[j].timeUpgrade = malloc(sizeof(char) * SIZE_CHAR);
        packages[j].timeRemove = malloc(sizeof(char) * SIZE_CHAR);
    }
    int i = 0;
    int installed = 0;
    int upgraded = 0;
    int removed = 0;

    FILE *fd;
    fd = fopen(logFile, "r");

    int fw = open(report, O_CREAT | O_RDWR | O_TRUNC, 0664);

    if (fw == -1)
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[BUFF_SIZE];
    char date[50];
    char *line;
    while (fgets(buffer, BUFF_SIZE, (FILE *)fd))
    {
        // while (fr = read(fd,buffer,BUFF_SIZE)){
        if (strstr(buffer, "[ALPM] installed") != NULL)
        {
            line = strtok(buffer, " ");
            line++;
            strcpy(packages[i].timeInstall, line);
            strcpy(packages[i].timeUpgrade, line);
            line = strtok(NULL, "]");
            strcat(packages[i].timeInstall, " ");
            strcat(packages[i].timeUpgrade, " ");
            strcat(packages[i].timeInstall, line);
            strcat(packages[i].timeUpgrade, line);
            line = strtok(NULL, " ");
            line = strtok(NULL, " ");
            line = strtok(NULL, " ");
            strcpy(packages[i].name, line);
            installed++;
            i++;
        }
        else if (strstr(buffer, "[ALPM] upgraded") != NULL)
        {
            line = strtok(buffer, " ");
            line++;
            strcpy(date, line);
            line = strtok(NULL, "]");
            strcat(date, " ");
            strcat(date, line);
            line = strtok(NULL, " ");
            line = strtok(NULL, " ");
            line = strtok(NULL, " ");
            strcpy(markup, line);
            j = 0;
            while ((strcmp(markup, packages[j].name)))
            {
                j++;
            }
            strcpy(packages[j].timeUpgrade, date);
            packages[j].upgrades++;
            upgraded++;
        }
        else if (strstr(buffer, "[ALPM] removed") != NULL)
        {
            line = strtok(buffer, " ");
            line++;
            strcpy(date, line);
            line = strtok(NULL, "]");
            strcat(date, " ");
            strcat(date, line);
            line = strtok(NULL, " ");
            line = strtok(NULL, " ");
            line = strtok(NULL, " ");
            strcpy(markup, line);
            j = 0;
            while ((strcmp(markup, packages[j].name)))
            {
                j++;
            }
            strcpy(packages[j].timeRemove, date);
            removed++;
        }
        memset(buffer, ' ', 1000);
    }
    char *text = malloc(sizeof(char) * LINE_LENGHT);
    int length = 0;

    length = snprintf(text, LINE_LENGHT, "Pacman Packages Report\n");
    //write(1,text,length);
    write(fw, text, length);

    length = snprintf(text, LINE_LENGHT, "----------------------\n");
    //write(1,text,length);
    write(fw, text, length);

    length = snprintf(text, LINE_LENGHT, "- Installed Packages\t: %d\n", installed);
    //write(1,text,length);
    write(fw, text, length);

    length = snprintf(text, LINE_LENGHT, "- Removed Packages\t: %d\n", removed);
    //write(1,text,length);
    write(fw, text, length);

    length = snprintf(text, LINE_LENGHT, "- Upgraded Packages\t: %d\n", upgraded);
    //write(1,text,length);
    write(fw, text, length);

    length = snprintf(text, LINE_LENGHT, "- Current Installed\t: %d\n\n", installed - removed);
    //write(1,text,length);
    write(fw, text, length);

    length = snprintf(text, LINE_LENGHT, "List Of Packages\n");
    //write(1,text,length);
    write(fw, text, length);

    length = snprintf(text, LINE_LENGHT, "----------------\n");
    //write(1,text,length);
    write(fw, text, length);

    int k = 0;
    while (packages[k].name[0]){
        length = snprintf(text, LINE_LENGHT, "-Package Name\t: %s\n", packages[k].name);
        //write(1,text,length);
        write(fw, text, length);

        length = snprintf(text, LINE_LENGHT, "   -Install Date\t: %s\n", packages[k].timeInstall);
        //write(1,text,length);
        write(fw, text, length);

        length = snprintf(text, LINE_LENGHT, "   -Last Update Date\t: %s\n", packages[k].timeUpgrade);
        //write(1,text,length);
        write(fw, text, length);

        length = snprintf(text, LINE_LENGHT, "   -How Many Updates\t: %d\n", packages[k].upgrades);
        //write(1,text,length);
        write(fw, text, length);

        if (packages[k].timeRemove[0])
        {
            length = snprintf(text, LINE_LENGHT,"   -Removal Date\t: %s\n", packages[i].timeRemove);
            //write(1,text,length);
            write(fw, text, length);
        }
        else
        {
            length = snprintf(text, LINE_LENGHT,"   -Removal Date\t: -\n");
            //write(1,text,length);
            write(fw, text, length);
        }
        k++;
    }
    if (fclose(fd) || close(fw) < 0){
        perror("Error closing file");
        exit(1); 
    }
    printf("Report is generated at: [%s]\n", report);
}