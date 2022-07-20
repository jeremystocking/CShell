#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include"history.h"
#define PATH_MAX 3333
void getcurrentwd(){
	char cwd[PATH_MAX];
	if(getcwd(cwd, sizeof(cwd)) != NULL){
        	printf("Current working directory: %s\n", cwd);
                if(commands < MAXHISTORY){
                	history[commands - 1]->exitStatus = 0;
                } else {
                        history[MAXHISTORY - 1]->exitStatus = 0;
                }
	} else {
                perror("getcwd() error");
                if(commands < MAXHISTORY){
                	history[commands - 1]->exitStatus = 1;
                } else {
                        history[MAXHISTORY - 1]->exitStatus = 1;
                }
        }
}
