#include <stdlib.h> 

int mystrlen(char *str){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

char *mystradd(char *origin, char *addition){
    char *newstr = malloc(sizeof(char)*mystrlen(origin)+ mystrlen(addition));
    int i = 0;
    int j = 0;
    while(origin[i] != '\0'){
        newstr[i] = origin[i];
        i++;
    }
    
    while(addition[j] != '\0'){
        newstr [i] = addition[j];
        i++;
        j++;
    }
    return newstr;
}

int mystrfind(char *origin, char *substr){
    int i = 0;
    int j = 0;
    int aux = 0;
    int sublen = mystrlen(substr);
    while(origin[i] != '\0'){
        aux = i;
        while(origin[i] == substr[j] && origin[i] != '\0' && substr[j] != '\0'){
            i++;
            j++;
        }
        if(j == sublen){
            return aux;
        }
            j = 0;
            i = aux;
            i++;

    }
    return -1;
}
