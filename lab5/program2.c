#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(){

   int fd[2];
   char filename[MAX_SIZE] = "";
   char *viewFile = "image.jpg";
   fd[1] = open(viewFile, O_RDWR);
   char *memory_file;
   struct stat bytes;

   if(fork() == 0)
   {
      execlp("display", "display", "-update", "1", viewFile, NULL);
   }

   else
   {
      while(filename[0] != 'q')
      {   
         printf("Enter file: ");
         scanf("%s",filename);

         fd[0]=open(filename, O_RDONLY);

         if(stat(filename, &bytes) == -1 && filename[0] != 'q')
         {
            fprintf(stderr, "File does not exist\n");
         }

         ftruncate(fd[1], bytes.st_size); 
         memory_file = mmap(NULL, bytes.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd[1],0);
         read(fd[0], memory_file, bytes.st_size);
         close(fd[0]);
      }
      
      if(munmap(memory_file, bytes.st_size) == -1)
      {  
         fprintf(stderr, "Unmap error \n");
      }
   }
}
