CC=gcc
CFLAGS=-c
SOURCES=main.c pokedex.c pokemon.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=pokemon_manage_service

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