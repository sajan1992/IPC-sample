#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(int argv,char * args[])
{
	char buff[100];
	int fd=(int)args[1];
	int count;
	memset(buff,'\0',100);
	count = read(fd,buff,39);
	buff[count]='\0';
	printf("In %s : read successfully %d bytes -> %s\n",__FILE__,count,buff);

}
