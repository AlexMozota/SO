all: sala jugador

sala: sala.o
	gcc sala.o -o sala

sala.o: sala.c
	gcc -c sala.c -o sala.o

jugador: jugador.o
	gcc jugador.o -o jugador

jugador.o: jugador.c
	gcc -c jugador.c -o jugador.o

clean:
	rm -r jugador jugador.o sala sala.o

test:
	./sala 60 5 AAAA

run:
	./sala $(ARGS)
