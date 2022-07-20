#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<unistd.h>
#define MAXLINE 4096
#include"strTok.h"
#include"history.h"

char* tokens[100];
int numTokens;

void tokenizeString(char* bfr){
        char bfrcpy[MAXLINE];
        int i = 0;
        strcpy(bfrcpy, bfr);
        char* token = strtok(bfrcpy, " ");
        numTokens = 0;
        while(token != NULL){
                tokens[i++] = token;
                token = strtok(NULL, " ");
                numTokens++;
        }
}
