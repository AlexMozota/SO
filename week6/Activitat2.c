#include <stdio.h>
#include <unistd.h>
#include <erno.h>
#include <sys/types.h>

 void main(){
     
     // Declarem el nostre array per emmagatzemar els descriptor associats a una pipe    
     int     fd[2];
     int    fd1[2];
     pid_t   pidFill;
     /* El primer element de la matriu (fd[0]) està configurat i obert per a la lectura, 
        mentre que el segon element està configurat i obert per escriure (fd[1]. 
        Totes les dades que viatgen per la canonada es mouen pel nucli. */
     
     pipe(fd);
     pipe(fd1);

     pidFill = fork();
        
     if(pidFill == -1){
        perror("fork");
        exit(1);
     } else if (pidFill == 0){
         /*El procés fill tanca la escriptura per la pipe*/
         close(fd[1]);
         close(fd1[0]);
     } else {
         /* El procés pare tanca la lectura per la pipe */
         close(fd[0]);
         close(fd1[1]);
     }
 }