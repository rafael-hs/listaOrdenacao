all: lista.o progLista.o
		gcc -o ordenacao *.o
		
lista.o: lista.c
		gcc -c lista.c
		
progLista.o: ordenacao.c
		gcc -c ordenacao.c
		
clean:
		rm -f *.o ordenacao
