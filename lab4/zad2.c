#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<fcntl.h>
  
#define BUFFER_SIZE 256


int main(int argc, char const *argv[])
{
    char buffer[BUFFER_SIZE];
    const char* filename;
    int flag, num;
	pid_t parent, child;

	int pipe1[2];
    
    if (pipe(pipe1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    child = fork();

    if (child == 0)
    {
        close(pipe1[1]);
        close(0);
        dup(pipe1[0]);
        close(pipe1[0]);
        execlp("display","display","-",NULL);
    }
    else 
    {
        if(argc<2)
        {
            fprintf(stderr, "%s\n", "Error: file not given");
            return 1;
        }
        
        if(argc>2)
        {
            fprintf(stderr, "%s\n", "Error: too many args");
            return 1;
        }

        filename = argv[1];
        close(pipe1[0]); 

	    if((flag = open(filename, O_RDONLY)) < 0) 
        {
            fprintf(stderr, "%s\n", "Error: opening file");
	        return 1;
        }

        while((num = read(flag, &buffer, BUFFER_SIZE)) > 0)
        {
            write(pipe1[1], &buffer, num);
        }
        
        close(flag);
        close(pipe1[1]);
        wait(NULL);
        
        exit(EXIT_SUCCESS);
    }

    return 0;
}
