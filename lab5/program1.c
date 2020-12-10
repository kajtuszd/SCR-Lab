#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_SIZE 128


int main() 
{
    const char *view_file = "view.txt";
    int fd = open(view_file, O_RDWR);
    char *memory_file;
    char filename[MAX_SIZE] = "";
    while (filename[0] != 'q') 
    {
        printf("Enter file: ");
        scanf("%s", filename);
        struct stat bytes;
        if (stat(filename, &bytes) == -1 && filename[0] != 'q') 
        {
            fprintf(stderr, "File does not exist\n");
        }
        ftruncate(fd, bytes.st_size);
        memory_file = mmap(NULL, bytes.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        int read_file = open(filename, O_RDONLY);
        read(read_file, memory_file, bytes.st_size);
        close(read_file);
    }
}