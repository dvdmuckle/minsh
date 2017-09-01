/*
 * =====================================================================================
 *
 *       Filename:  minsh.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2017 03:14:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
char *user;
char *host;
int main(int argc, char** argv)
{
	int should_run = 1;
	user = getlogin();
	gethostname(host, 20);
	while (should_run){   
		printf("%s@%s> ", user, host);
		fflush(stdout);
		char *command[20];
		fgets(*command, 20, stdin);
		printf(*command);
		/* int rc = fork();
		if(rc<0){
			printf("Fork failed!");
		}
		if(rc == 0){
			
		}*/
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
