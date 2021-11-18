#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
int a=25;
int main(){
    if (fork()==0){
      a=a+5;
      printf("x=%d, y=%dn", a, &a);
    }
    else{
        a=a-5;
        printf("u=%d, v=%dn", a, &a);
    }
}

