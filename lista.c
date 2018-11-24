#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/***

	ESTE ARQUIVO CONTEM A IMPLEMENTACAO DE TODAS AS FUNCOES LISTADAS NO ARQUIVO "lista.h".

	A TIPO DE RETORNO E A LISTA DE PARAMETROS DAS FUNCOES DEVE OBEDECER AS ASSINATURAS
	DESSAS FUNCOES QUE ESTA NO ARQUIVO "lista.h".

	SE FOR IMPLEMENTAR UMA NOVA FUNCAO, COLOQUE A ASSINATURA DELA NO "lista.h" E DEPOIS
	A IMPLEMENTE NESTE ARQUIVO

	ESTE ARQUIVO DEVE CONTER APENAS AS FUNCOES USADAS PARA A MANIPULACAO DO TAD PILHA E
	ELE NAO CONTEM A FUNCAO "main()".

***/

/**
FUN��O: novaLista
DESCRI��O: Fun��o que cria uma nova lista para armazenar os elementos. Esta fun��o j� vai
        alocar espa�o para a estrutura cabe�alho da lista (Lista) e inicializar os campos
        desta estrutura, o ponteiro que aponta para o in�cio da lista.
ENTRADA:
SA�DA: Lista* - que � a refer�ncia da estrutura cabe�alho.
**/
Lista* novaLista()
{
    // Aloca dinamicamente um espa�o para a estrutura cabe�alho. Para realizar a aloca��o
    // din�mica de mem�ria, usa-se a fun��o malloc(). Esta fun��o, conforme foi implementada,
    // retorna um ponteiro para void (void*). � feita uma convers�o expl�cita deste ponteiro
    // para void, para um ponteiro para um Lista (Lista*).
    Lista* l = (Lista*)malloc(sizeof(Lista));

    // inicializando os campos da estrutura. Neste caso, como a lista inicialmente n�o possui
    // elementos, os campos da estrutura s�o incializados com NULL.
    l->inicio = NULL;

    // retornando a estrutura cabe�alho.
	return l;
}

/**
FUN��O: listaVazia
DESCRI��O: Fun��o que verifica se uma lista est� vazia. A lista est� vazia quando ela n�o
        possui elementos, ou seja, quando o ponteiro da estrutura cabe�alho est�
        apontando para NULL.
ENTRADA: Lista* - a refer�ncia para uma lista.
SA�DA: int - representando ou o valor l�gico VERDADEIRO (1), ou o valor l�gico FALSO (0).
**/
int listaVazia(Lista* l)
{
	if(l->inicio == NULL)
		return 1;
	else return 0;
}

/**
FUN��O: push
DESCRI��O: Fun��o que insere um novo elemento em uma lista. A fun��o cria um elemento do
        tipo n� e insere este elemento na �ltima posi��o da lista.
ENTRADA: Lista* - a refer�ncia para uma lista.
         elem - o valor do elemento a ser inserido
SA�DA: Lista* - a refer�ncia para a lista com o  novo elemento inserido.
**/
Lista* push(Lista* l, int elem)
{
	// Cria uma nova caixinha para armazenar o novo elemento. Este elemento � do tipo
	// n� lista. Portanto, ao usar o malloc para criar dinamicamente este novo elemento
	// devemos converter o retorno da fun��o malloc para o tipo NoLista.
	No *novo = (No*)malloc(sizeof(No));
	// Preenche os campos da caixinha
	novo->valor = elem;		// Atribui o valor
	novo->prox = NULL;		// O pr�ximo na nova caixinha recebe NULL

    // Verifica se a lista est� vazia.
    if(listaVazia(l))
    {
        // Caso esteja, o novo elemento a ser inserido, ser� tanto o primeiro quanto
        // o �ltimo elemento da lista. Logo temos que apontar os dois ponteiros do
        // cabe�alho (prim e ult) para este elemento.
        l->inicio = novo;
    }
    // Caso a lista n�o esteja vazia, o novo elemento deve ser inserido no final da lista.
    else
    {
        // declara um aux que aponta para o in�cio da lista.
        No *aux = l->inicio;

		// enquanto o aux for diferente de NULL, anda com ele para adiante... at� o �ltimo
		// elemento da lista
		while(aux->prox != NULL)
			aux = aux->prox;

        // liga o �ltimo elemento da lista ao novo elemento.
        aux->prox = novo;
    }

	// Retorna a estrutura cabe�alho da lista
	return l;
}

Lista* pushOrdenado(Lista* l, int elem)
{
	
	No* novo = (No*)malloc(sizeof(No));
	novo->valor = elem;

	if(l->inicio == NULL)
	{
		l->inicio = novo;
		novo->prox = NULL;
	}
	else
	{
		if(l->inicio->valor >= novo->valor)
		{
			novo->prox = l->inicio;
			l->inicio = novo;
		}
		else
		{
			No *aux = l->inicio;
			while(aux->prox !=NULL && aux->prox->valor <= elem)
				aux=aux->prox;
				
			if(aux->prox != NULL)
			{
				novo->prox = aux->prox;
				aux->prox = novo;
			}
			else
			{
				aux->prox = novo;
				novo->prox = NULL;
			}
		}
	}
	return l;
}

/**
FUN��O: pop
DESCRI��O: Fun��o que remove um elemento da lista de acordo com o valor do elemento. A fun��o
		certifica que a lista n�o est� vazia para remover o primeiro elemento.
ENTRADA: Lista* - a refer�ncia para uma lista.
		 int - elemento a ser removido.
SA�DA: Lista* - a refer�ncia para a lista com o primeiro elemento removido, se houver pelo
        menos um elemento na lista. Caso contr�rio o retorno ser� NULL.
**/
Lista* pop(Lista* l, int elem)
{
	// Verifica se a lista est� vazia
	if(listaVazia(l))
	{
	    // Retorna NULL para sinalizar que a lista esta vazia
	    return l;
	}

	// Caso a lista n�o esteja vazia, declara um aux que aponta para o in�cio da lista.
	No *aux = l->inicio;

	// Verifica se o elemento a ser removido � o primeiro
	if(aux->valor == elem)
	{
		l->inicio = aux->prox;
		free(aux);

		printf("\nElemento removido com sucesso\n\n");
	}
	else
	{
		// Percorre a lista em busca do elemento a ser removido
		while(aux->prox != NULL && aux->prox->valor != elem)
			aux = aux->prox;

		// Se o elemento foi encontrado
		if(aux->prox != NULL && aux->prox->valor == elem)
		{
			// Declara um ponteiro que aponta para o elemento a ser removido
			No *aux2 = aux->prox;

			// Liga o anterior ao pr�ximo do elemento a ser removido
			aux->prox = aux2->prox;

			// Apaga o elemento
			free(aux2);

			printf("\nElemento removido com sucesso\n\n");
		}
		else
			printf("\nElemento nao existe na lista\n\n");
	}

	// Retorna a estrutura cabe�alho l, que agora est� sem o primeiro elemento
	return l;
}

/**
FUN��O: pesquisar
DESCRI��O: Fun��o que retorna a refer�ncia de um elemento da lista.
ENTRADA: Lista* - a refer�ncia para uma lista.
		 int - elemento a ser pesquisado.
SA�DA: No* - a refer�ncia para o elemento da lista.
**/
No* pesquisar(Lista* l, int elem)
{
	// Verifica se a lista n�o est� vazia
	if(!listaVazia(l))
	{
		// Caso a lista n�o esteja vazia, declara um aux que aponta para o in�cio da lista.
		No *aux = l->inicio;

		// Percorre a lista em busca do elemento
		while(aux != NULL && aux->valor != elem)
			aux = aux->prox;

		// Se o elemento foi encontrado
		if(aux != NULL && aux->valor == elem)
		{
			// Retorna o elemento
			return aux;
		}
	}

	// Ou a lista est� vazia ou o elemento n�o existente
	return NULL;

}

void percorreListaPush(Lista *l, Lista *lo)
{
	No *aux = l->inicio;
	while(aux != NULL)
	{
		pushOrdenado(lo,aux->valor);
		aux = aux->prox;
	}
}

/**
FUN��O: imprimeLista
DESCRI��O: Fun��o que exibe na tela todos os elementos existentes na lista.
ENTRADA: Lista* - a refer�ncia para uma lista.
SA�DA: void - como a fun��o exibe os elementos e para isso ela n�o altera em nada a lista,
        a fun��o retorna void.
**/
void imprimeLista(Lista *l)
{
    // Todos os elementos a serem exibidos na tela s�o do tipo NoLista.
	No *aux = l->inicio;

    // Enquanto houver elemento na lista, ou seja, enquanto o ponteiro que percorre todos
    // os Nolista's for diferente de NULL
	while(aux != NULL)
	{
	    // Exibe o dado preenchido no campo valor
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
}