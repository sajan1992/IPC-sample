#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define SIZE 5
int main()
{
	int count,ec;
	pid_t ret;
	int pipes[2];
	pipe(pipes);
	char Msg1[]="Hello there! My name is sajan kumar jha";
	char Ret[strlen(Msg1)];
	memset(Ret,'\0',strlen(Msg1)+1);

	ret = fork();

	switch(ret)
	{
		case -1:
 			perror("fork");
			close(pipes[1]);
			close(pipes[0]);
			exit(EXIT_FAILURE);
		case 0:
			printf("In Child->PID: %d Begins\n",getpid());
			printf("In Child: recieved Read fd = %d , Write fd = %d\n",pipes[0],pipes[1]);			
			char x=(char)pipes[0];
			printf("value of x= %s\n",x);
			//count = read(pipes[0],Ret,strlen(Msg1));
			//execl("./arg","arg.c",x,NULL);
			printf("In Child: read %d bytes of data -> %s\n",count,Ret);
			printf("Child Ends : %d\n",getpid());
			close(pipes[0]);
			break;
		default:
			sleep(5);
			printf("In parent->PID: %d Begins\n",getpid());
			printf("In parent: recieved Read fd = %d , Write fd = %d\n",pipes[0],pipes[1]);			
			count = write(pipes[1],Msg1,strlen(Msg1));
			printf("In parent: Write process complete, wrote %d bytes of data\n",count);
			close(pipes[1]);
			if(ret)
			{
				wait(&ec);
				if(WIFEXITED(ec))
					printf("WEXITSTATUS = %d\n",WEXITSTATUS(ec));	
			
				printf("Parent Ends : %d\n",getpid());
			}
	}


return 0;
	


}
