#include <stdio.h>
int main(){
    const char *s="";
    char str[]= "Hola";
    while (*s){
        printf("%c", *s++);
    }
    return 0;
}