#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

void menu()
{
	printf("1. Inserir um novo elemento\n");
	printf("2. Apagar um elemento\n");
	printf("3. Pesquisar um elemento da lista\n");
	printf("4. Imprimir todos os elementos da lista\n");
	printf("5. Sair\n");
}

int main()
{
	int opcao, num;
	Lista *l = novaLista();

	do
	{
		menu();
		printf("Digite a sua opcao: ");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("clear");
				printf("\nDigite o numero a inserir: ");
				scanf("%d", &num);
				l = push(l, num);

				system("clear");
				printf("\nNumero adicionado com sucesso\n\n");
				break;

			case 2:
				system("clear");
				if(listaVazia(l))
					printf("\nErro ao remover! A lista estah vazia\n\n");
				else
				{
					printf("Informe o numero a ser removido; ");
					scanf("%d", &num);
					l = pop(l, num);
				}
				break;

			case 3:
				system("clear");
				printf("Informe o numero a ser pesquisado: ");
				scanf("%d", &num);
                No *t = pesquisar(l, num);
				if(t != NULL)
					printf("\nElemento: %d\n\n", t->valor);
				else
					printf("\nElemento %d nao existe na lista\n\n", num);
				break;

			case 4:
				system("clear");
				printf("\n");
				imprimeLista(l);
				printf("\n");

				break;

			case 5:
				system("clear");
				printf("\nSaindo do sistema!\n\n");
				break;

			default:
				system("clear");
				printf("\nOpcao invalida!\n\n");
		}
	} while (opcao != 5);

    return 0;
}
