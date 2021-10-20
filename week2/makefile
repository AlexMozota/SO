$vi Makefile_v2

CFLAGS=-c
SOURCES=main_v2.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main_v2
 
all: $(SOURCES) $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJECTS)
$(CC) $(OBJECTS) -o $@
 
.c.o:
$(CC) $(CFLAGS) $< -o $@
 
execute: $(EXECUTABLE)
./$(EXECUTABLE)
 
clean:
/bin/rm -rf *.o
/bin/rm -rf $(EXECUTABLE)