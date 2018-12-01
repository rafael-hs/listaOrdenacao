#ifndef __LISTA_H_
#define __LISTA_H_

//estrutura usada para a lista
//region
typedef struct no
{
	int valor;
	struct no *prox;
} No;

typedef struct lista
{
		int size;
    No *inicio;
} Lista;
//endregion


//lista de funcoes do programa

Lista* novaLista();
int listaVazia(Lista*);
Lista* push(Lista*, int);
Lista* pushOrdenado(Lista*, int);
Lista* pop(Lista*, int);
No* pesquisar(Lista*, int);
int index(Lista* , No*);
void trocaNo(Lista*, No*, No*);
No* atPos(Lista*, int);
void ordenacaoSort(Lista*);
void imprimeLista(Lista*);
No* menor(Lista*, int);
int anteriorM(Lista*, int);
int anteriorI(Lista*, int);
void ordena(Lista*);
void ordenacao(Lista*);
void ordena2(Lista*);
void percorreListaPush(Lista*, Lista*);
void ordenaVezes(Lista*);

#endif /*__LISTA_H_*/
