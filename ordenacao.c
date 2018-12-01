#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

void menu()
{
	printf("1. Inserir elementos na lista\n");
	//printf("2. Apagar um elemento\n");
	//printf("3. Pesquisar um elemento da lista\n");
	//printf("4. Imprimir todos os elementos da lista\n");
	printf("0. Sair\n");
}

int main()
{
	int num=0;
	Lista *l = novaLista();
	Lista *lo = novaLista();
	
	printf("digite a sequencia de numeros: \n");
	
	while(num>=0){
		scanf("%d", &num);
		if(num >= 1 && num <=1000)
		{
			if(num<0)
				break;
			else
				push(l,num);
		} 
	}
	
	system("clear");
	printf("\n");
	imprimeLista(l);
	printf("\n");
	trocaNo(l, l->inicio->prox,l->inicio->prox->prox);
	int numeroi; 
	//No *aux = atPos(l, 1);
	ordenacaoSort(l);
	//percorreListaPush(l, lo);
	//printf("%d: \n", menor(l,0));
	printf("\n");
	imprimeLista(l);
	printf("\n");
	//printf("\n%d:",numeroi);
	//trocaNo(l,l->inicio,l->inicio->prox->prox->prox);
	//printf("\n %d:", atPos(l, 5)->valor);
	//printf("%d tamanho \n",l->size);
	printf("\n");
	imprimeLista(l);
	printf("\n");
	
 return 0;
}














