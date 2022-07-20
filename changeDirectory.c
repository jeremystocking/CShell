#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>
#include"history.h"
#include"strTok.h"
#define PATH_MAX 3333
void changeDirectory(char* directory){

        if(strcmp(directory, "") == 0){
		fputs("Specificy directory to change to after command cd.\n", stderr);
        	if(commands < MAXHISTORY){
                        history[commands - 1]->exitStatus = 1;
                } else {
                        history[MAXHISTORY - 1]->exitStatus = 1;
                }
	} else {
	char prevDir[PATH_MAX];
	getcwd(prevDir, PATH_MAX);
	chdir(directory);
	char newDir[PATH_MAX];
	getcwd(newDir, PATH_MAX);
	if(strcmp(prevDir, newDir) == 0){
        	if(commands < MAXHISTORY){
                	history[commands - 1]->exitStatus = 1;
                } else {
                        history[MAXHISTORY - 1]->exitStatus = 1;
                }
			strcat(directory, ": No such file or directory\n");
			fputs(directory, stderr);
        } else {
		printf("%s\n", newDir);
                if(commands < MAXHISTORY){
                        history[commands - 1]->exitStatus = 0;
                } else {
                        history[MAXHISTORY - 1]->exitStatus = 0;
                }
        }
}}
