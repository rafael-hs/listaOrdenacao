all: lista.o progLista.o
		gcc -o progLista *.o
		
lista.o: lista.c
		gcc -c lista.c
		
progLista.o: progLista.c
		gcc -c progLista.c
		
clean:
		rm -f *.o progLista
