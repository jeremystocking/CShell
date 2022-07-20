#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include"strTok.h"
#include<stdlib.h>

int retrievedStatus;

void executeExternalCommand(char* bfr){

	int pid = fork();
	char *args[50];
	int i;
	for(i = 0; i < numTokens; i++){
		args[i] = tokens[i];
	}
	args[i++] = NULL;
	if(pid != 0){
                wait(&retrievedStatus);
		setvbuf(stdout, NULL, _IONBF, retrievedStatus);
		
        } else if(pid == 0) {
		execvp(args[0], args);
		retrievedStatus = 127;
		fputs("Command not recognized.\n", stderr);
		exit(127);
	} else {
		perror("Fork failed");
		retrievedStatus = -1;
	}
}
