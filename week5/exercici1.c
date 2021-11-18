#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
   FILE *psFile;
   psFile = fopen("temp.txt", "w");
signal(SIGINT,SIG_IGN);
   fclose(psFile);
   remove("temp.txt");
   return 0;
}