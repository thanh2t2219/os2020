#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	printf("\n\nMain before fork()\n");
	int pid1 = fork();
	if (pid1==0){

		int pid2 = fork();
		if (pid2==0){
			printf("I am chid after fork(), launching ps -ef\n");		
			char *args[]= {"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", args);
			printf("Finished launching ps -ef\n");
		}

		else {
			wait(NULL);
// A call to wait() blocks the calling process until one of its child processes exits or a signal is received //

			printf("I am parent after fork(), child is %d\n", pid2);
		}

		printf("I am child after fork(), launching free -h\n");
		char *args[]= {"free", "-h", NULL};
		execvp("free", args);
	}

	else {
		wait(NULL);
		printf("I am parent after fork(), child is %d\n", pid1);	
	}
	
	return 0;
}
