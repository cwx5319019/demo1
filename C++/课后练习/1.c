#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int savefd = dup(1);
	int fd = open("1.txt",O_RDWR | O_CREAT,0666);
	int newfd = dup2(fd,1);
	int a = 0;
	int b = 0;
	int c = a + b;
	printf("c = %d\n",c);
	system("objdump -D ./a.out");
	

	return 0;
}

