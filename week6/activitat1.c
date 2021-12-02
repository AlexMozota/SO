#include <unistd.h>

#include <stdlib.h>

#include <stdio.h>

#include <fcntl.h>

 

void main() {

int fd;

fork();

fd = open("out.txt", (O_CREAT|O_RDWR));

write(fd, "so\n", 3);

close(fd);

exit(0);

}