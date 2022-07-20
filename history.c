#include<stdio.h>
#include"smash.h"
#include"history.h"
#include<stdlib.h>
#include<string.h>
#define MAXHISTORY 10
#define MAXLINE 4096

Cmd **history;
//int i;
int commands;

void init_history(void){
	history = (Cmd **) malloc(MAXHISTORY * sizeof(Cmd *));
	for(int i = 0; i < MAXHISTORY; i++){
		history[i] = (Cmd *) malloc(sizeof(Cmd));
		history[i]->cmd = (char *) malloc(MAXLINE * sizeof(char));
	}
	commands = 0;
}

void add_history(char* bfr, int exitStatus){
	int i;
	if(commands < MAXHISTORY){
        	strncpy(history[commands]->cmd, bfr, strlen(bfr));
                history[commands]->cmd[strlen(bfr)] = '\0';
                commands++;
        } else {
        	for(i = 0; i < commands - 1; i++){
                	strcpy(history[i]->cmd, history[i + 1]->cmd);
                        history[i]->exitStatus = history[i + 1]->exitStatus;
                }
                strncpy(history[commands - 1]->cmd, bfr, strlen(bfr));
               	history[commands - 1]->cmd[strlen(bfr)] = '\0';
		history[i]->exitStatus = exitStatus;
	}
}

void clear_history(void){
	for(int i = 0; i < MAXHISTORY; i++){
                free(history[i]->cmd);
                free(history[i]);
        }
        free(history);
}

void print_history(int firstSequenceNumber){
	for(int i = firstSequenceNumber; i < commands; i++){
        	printf("%d  ", i + 1);
                printf("[%d] ", history[i]->exitStatus);
                puts(history[i]->cmd);
	}
	if(commands < MAXHISTORY){
                history[commands - 1]->exitStatus = 0;
        } else {
        	history[MAXHISTORY - 1]->exitStatus = 0;
        }
}
