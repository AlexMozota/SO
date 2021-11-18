#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main() {

int p1,p2;



p1=fork();

switch(p1){

case 0: 

default:

p2=fork();

switch(p2){

case 0: 

default:

while(p1 != wait(NULL)){}

while(p2 != wait(NULL)){}

}

}

}