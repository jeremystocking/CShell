#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<unistd.h>
#include"history.h"
#include"commands.h"
#include"rmwhite.h"
#include"externalCommands.h"
#define MAXLINE 4096
#define MAXHISTORY 10

int main(){
	char bfr[MAXLINE];
	char tmpbfr[MAXLINE];
	int exitStatus = 0;
	fputs("$ ", stderr);

	init_history();
	
	while(fgets(bfr, MAXLINE, stdin) != NULL) {
		bfr[strlen(bfr) - 1] = '\0';
		strcpy(tmpbfr, bfr);
		removewhitespace(tmpbfr);
		 if(strlen(bfr) > MAXLINE){
                        fputs("User Input should not exceed 4095 characters\n", stderr);
                        continue;
                }else if(strlen(bfr) == 0 || strlen(tmpbfr) == 0){
                        fputs("Please enter a command:\n", stderr);
			continue;
                }
//exit:
		if(strcmp(bfr, "exit") == 0){
			break;
		}
//storing history:
		add_history(bfr, exitStatus);
//execute commands:
		executeCommand(bfr);
                fputs("$ ", stderr);
	}
	fputs("exiting...\n", stderr);
	clear_history();
	return exitStatus;
}
