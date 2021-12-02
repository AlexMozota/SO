#include <unistd.h>

#include <stdlib.h>

#include <stdio.h>

#include <fcntl.h>

 

void main() {

int fd;

fd = open("out.txt", (O_CREAT|O_RDWR));

fork();

write(fd, "so\n", 3);

close(fd);

exit(0);

}