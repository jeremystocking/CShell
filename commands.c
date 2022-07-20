#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>
#include<stdlib.h>
#include"history.h"
#include"strTok.h"
#include"changeDirectory.h"
#include"cwd.h"
#include"externalCommands.h"
#include"rmwhite.h"

void executeCommand(char* bfr){
//tokenize string
		tokenizeString(bfr);
//Internal Commands:
//change directory:
		removewhitespace(bfr);
                if(strcmp(tokens[0], "cd") == 0){
                        if(strlen(bfr) < 3){
				changeDirectory("");
                        } else {
                                changeDirectory(tokens[1]);
                        }
//history:
                }else if(strcmp(bfr, "history") == 0){
                        print_history(0);
//current woreking directory:
                } else if(strcmp(bfr, "cwd") == 0 || strcmp(bfr, "pwd") == 0){
                        getcurrentwd();
//external command:
                } else {
                        executeExternalCommand(bfr);
			//for(int i = 0; i < numTokens; i++){
                        //       printf("[%d] %s\n", i, tokens[i]);
   			//}
   			if(retrievedStatus > 0){
				retrievedStatus = 127;
			}
                        if(commands < MAXHISTORY){
                                history[commands - 1]->exitStatus = retrievedStatus;
                        } else {
                                history[MAXHISTORY - 1]->exitStatus = retrievedStatus;
                        }
                }	
}
