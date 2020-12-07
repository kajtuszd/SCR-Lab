#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO "/tmp/myfifo"


int main(){

	const int size = 128;
	int fd;
	int file_desc[10];
	int counter;			
	char buffer[size];
	char filename[64];
	char *myfifo = "tmp/myfifo";
	int i = 0;
	
	mkfifo(FIFO, 0666);
	printf("%s\n", "FIFO ready, type 'cat /tmp/myfifo' in other window \n ");
	fd = open(FIFO, O_WRONLY);

	
	if(fd == -1){
		fprintf(stderr, "%s\n", "Error: Pipe.");
	}


	while(1)
	{
		printf("Enter filename to read (q -> exit): ");
		scanf("%s", filename);
		
		if(filename[0] == 'q')
			break;
		
		file_desc[i] = open(filename, O_RDONLY);

		if(file_desc[i] < 0)
			puts("Error: Could not open file");
	
		while ((counter=read(file_desc[i], buffer, size)) > 0)
		{
			write(fd, buffer, counter);
		}
		++i;
	}

	close(fd);
	return 0;
}
