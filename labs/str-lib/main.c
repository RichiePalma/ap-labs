#include <stdio.h>
int mystrlen(char *);
char *mystradd(char *, char *);
int mystrfind(char *, char *);

int main(int argc,char *argv[]) {
    if(argc != 4){
        printf("Execute as following: ./main <OriginalString> <SubstringToAdd> <SubstringToFind>");
        return 1;
    }

    char *newstr = mystradd(argv[1],argv[2]);
    int pos = mystrfind(newstr,argv[3]);
    
    printf("Initial Length      : %i\n",mystrlen(argv[1]));
    printf("New String          : %s\n",newstr);

    if (pos != -1){
        printf("SubString was found : yes, at the %ith position\n",pos);
    }
    else{
        printf("SubString was found : no\n");
    }
    return 0;
}
