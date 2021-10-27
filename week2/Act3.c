#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 
int main (int argc, char * argv[]){
int *a,i,j,tmp,n;
char msg[250];
    sprintf(msg, "Introdueix un element de l'array: \n");
    write(1,msg,strlen(msg));
    scanf("%d", &n);
for(i=0; i<n; i++){ 
    sprintf(msg," a[%d]=%d: \n", i, *(a+i) );
    write(1, msg, strlen(msg));
    scanf("%d", a+i);
}
for(j=0; j<n; j++){
    for(i=0; i<n; i++){
        if(*(a+i)>*(a+j)){
            tmp=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=tmp;
        }
    }
}
for(i=0; i<n;i++){
    sprintf(msg," a[%d]=%d: \n", i, *(a+i) );
    write(1,msg,strlen(msg));
}
exit(0);
}
