#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
	printf("Execution starts now \n");
	printf("Enter the commands in terminal to execute as a different process\n");
	char buf[256];
	ssize_t size=0;;
	int fd[2];
	pipe(fd);
	while(1){
		printf("sun\n");
		int pid=fork();
		if(pid==0){

			//printf("devdhgew\n");
			size= read(0,buf,256);
			printf("%s  %d\n",buf ,size-1);
			printf("sun %d\n",strcmp(buf, "exit\n") );
			dup(fd);
			exit(0);
		}
		else if(pid>0){
			//printf("sdwe\n");
			wait(NULL);
			printf("atul %d\n",strcmp(buf, "exit\n") );
			if(strcmp(buf, "exit\n") == 0){
				break;
			}
			printf("defcerfreer\n");
		}
		else{
			printf("Failed to fork\n");
		}
	}
	return 0;








	/*char buf[5];
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (pid == 0){
		
		write(fd[1], "hello", 5);

	}
	else{
		wait();
		read(fd[0], buf, 5); 
		 // parent sends “hello”
	}

	printf("%s\n", buf);
*/
}
