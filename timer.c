/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

int count = 0;
int sec = 0;
bool check = true;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was right!\n");
  alarm(1); //exit after printing
}
void sigintHandler(int sig_num)
{
  signal(SIGINT, sigintHandler);
  printf("\n %d no of alarms occured for %d seconds\n", count,sec);
  check = false;
}
int main(int argc, char * argv[])
{
  while (check){
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    sleep(1);
    signal(SIGINT, sigintHandler);
    count ++;
    sec ++;
  } //busy wait for signal to be delivered
  
  return 0; //never reached
}