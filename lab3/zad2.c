#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void term()
{
  printf("Goodbye!\n");
  exit(0);
}

void alrm()
{
  printf("BEEP BEEP\n");
}

void usr1()
{
  printf("Stopped for 10 iterations\n");
  for(int i=0;i<10;i++)
  {
    printf("%d ",i);
    sleep(1);    
  }

}

void usr2(){}

int main()
{

  signal(SIGTERM, term);
  signal(SIGALRM, alrm);
  signal(SIGUSR1, usr1);
  signal(SIGUSR2, usr2);
  
  while (1)
  {
    printf("Still working...\n");
    sleep(1);
  }  
  return 0;
}