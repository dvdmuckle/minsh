/*
 * =====================================================================================
 *
 *       Filename:  minsh.c
 *
 *    Description:  A simple shell
 *
 *        Version:  1.0
 *        Created:  08/31/2017 03:14:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David Muckle, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
typedef int bool;
#define true 1
#define false 0
char *user;
char host[20];
bool verbose = false;
int main(int argc, char** argv)
{
	int should_run = 1;
	for(int i = 0; i < argc; i++){
		if(strcmp(argv[i], "-v") != 0 && strcmp(argv[i], "--help") != 0 && i>=1){
			printf("Invalid flag, use --help for more information\n");
			exit(1);
		}
		if(strcmp(argv[i], "-v") == 0){
			verbose = true;
			printf("Running in verbose mode\n");
		}
		if(strcmp(argv[i], "--help") == 0) {
			printf("Minsh - a simple shell\n-v - Start in verbose mode\nMinsh is a simple shell that supports commands and stdout redirection\n");
			exit(0);
		}
	}
	if(verbose){
		printf("Getting user and hostname for custom prompt\n");
	}
	user = getlogin();
	gethostname(host, 20);
	while (should_run){   
		printf("%s@%s> ", user, host);
		fflush(stdout);
		char command[256];
		fgets(command, 256, stdin);
		strtok(command, "\n");
		if(strcmp(command, "exit") == 0){
			if(verbose){
				printf("Alright, we're exiting\n");
			}
			exit(0);
		}
		char *cmdArgs[128];
		int i=0;
		char initialCommand[256];
		if(verbose){
			strcpy(initialCommand, command);
		}
		cmdArgs[i] = strtok(command, " ");

		while(cmdArgs[i] != NULL){
			cmdArgs[++i] = strtok(NULL, " ");
		}
		int rc = fork();
		if(rc<0){
			printf("Fork failed!\n");
		}
		else if(rc == 0){
			if(verbose){
				printf("Fork successful, running %s\n", initialCommand);
			}
			execvp(command, cmdArgs);	
		}
		else{
			wait(NULL);
			if(verbose){
				printf("We're done waiting, return back to prompt\n");
			}
		}
	} 

	return 0;
}
