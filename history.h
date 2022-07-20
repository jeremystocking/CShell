#ifndef HISTORY_H
#define HISTORY_H
#define MAXHISTORY 10 //Smash will save the alst ten commands

extern int commands;
//extern int i;

//Define the layout of a single entry in the history array
typedef struct Cmd_struct {
	char* cmd; //A saved copy of the suer's command string
	int exitStatus;	//The exit status from this command
} Cmd;

extern Cmd** history;

//Function prototypes for the command history feature
void init_history(void); //Builds data structures for recording cmd history
void add_history(char* cmd, int exitStatus); //Adds the entry to the history
void clear_history(void); //Frees all malloc'd memory in the history
void print_history(int firstSequenceNumber); //Print history tro stdout

#endif /*HISTORY_H*/
