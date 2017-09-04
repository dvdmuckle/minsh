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
	if(strcmp(argv[0], "-v")){
			verbose = true;
			printf("Running in verbose mode.\n");
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
			exit(0);
		}
		int rc = fork();
		if(rc<0){
			printf("Fork failed!");
		}
		if(rc == 0){
			execvp(command, NULL);	
		}
		/*
		 *          (0) Read user input, e.g. with fgets()
		 *          (1) fork a child process
		 *          (2) the child process will invoke execvp()
		 *          (3) the parent will invoke wait()
		 *  
		 */
	} // end while

	return 0;
}
