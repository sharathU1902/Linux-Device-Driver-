#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int fd,len,wc;
	char arr[] = "Hello Kernel";
	fd=open("/dev/mynode",O_WRONLY);
	if(!fd)
	{
		printf("Error opening VFS mynode");
		exit(-1);
	}
	len=strlen(arr);

	wc= write(fd, arr,len);	

	if(wc==-1)
	{
		printf("Error while writting into mynode\n");
		exit(-1);
	}
	printf("Written into the kernel sucessfully\n");

	close(fd);

return 0;
}
