#ifndef __LISTA_H_
#define __LISTA_H_

/***

    DEFINICAO DAS ESTRUTURAS DO TAD

    A nossa estrutura lista, vai ser composta por uma estrutura "cabe�alho" que cont�m um ponteiro
    que v�o apontar para o elemento que est� na primeira da lista. Esta estrutura cabe�alho se chama Lista.

    Os elementos da lista, ou seja, os dados em si, ser�o armazenados em outra estrutura, que representa
    os n�s da lista. Esta outra estrutura se chama No e � composta de um campo valor, que vai guardar
    o valor do elemento e um ponteiro para o pr�ximo n� da lista

 ***/

typedef struct no
{
	int valor;
	struct no *prox;
} No;

typedef struct lista
{
    No *inicio;
} Lista;

/*** DEFINICAO DOS CABECALHOS DAS FUNCOES DO TAD ***/

Lista* novaLista();
int listaVazia(Lista*);
Lista* push(Lista*, int);
Lista* pop(Lista*, int);
No* pesquisar(Lista*, int);
void imprimeLista(Lista*);

// SE HOUVER OUTRAS FUNCOES QUE SERAO IMPLEMENTADAS PELA LISTA, DECLARE AS ASSINATURAS DELAS AQUI

#endif /*__LISTA_H_*/
