#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include"cabecalho.h"

// Cria��o do enum para o tipo booleano
enum booleano { true = 0, false = 1 };
// Cria��o do tipo bool com base no enum booleano
typedef enum booleano bool;

// Defini��o da estrutura do no.
struct estrutura_no {
	int elemento;
	struct estrutura_no *proximo;
};

// Cria��o do tipo "TipoNo".
typedef struct estrutura_no TipoNo;

// fun��o limpa a tela. Funciona em Linux e Windows.
void clear_screen() {
	system("cls || clear");
}

// Vari�vel global cabeca da lista
TipoNo *cabeca = NULL;

// fun��o que verifica se a lista esta vazia
bool is_lista_vazia() {
	return (cabeca->proximo == cabeca);
}

/*
Fun��o: cria_no
Par�metros: sem par�metros
Retorno: endere�o para um novo "no" rec�m criado
Descri��o: A fun��o tem por objetivo criar um novo "no" e retornar seu endereco;
*/
TipoNo *cria_no() {
	TipoNo *novoNo;
	novoNo          = malloc(sizeof(TipoNo));
	novoNo->proximo = NULL;
	return novoNo;
}

// Criando a lista circular vazia
void cria_lista_vazia() {
	cabeca           = cria_no();
	cabeca->elemento = -1;
	cabeca->proximo  = cabeca;
}


// fun��o para imprimir a lista
void imprime_lista() {
	TipoNo *aux = cabeca->proximo;
	if (!is_lista_vazia()) {
		printf("Elementos atualmente na lista:\n");
		while (aux != cabeca) {
			printf("%d ", aux->elemento);
			aux = aux->proximo;
		}
	}
	else {
		printf("A lista esta vazia!");
	}
	printf("\n");
}


/*
   Busca elemento na lista retornando o endere�o do "no" qual o elemento se encontra.
   A fun��o retorna NULL se o elemento n�o pertence a lista.
*/
TipoNo *busca_circ(int pElemento) {
	// criacao dos ponteiros auxiliares
	TipoNo *anterior, *atual, *retorno = NULL;

	cabeca->elemento = pElemento;
	atual = cabeca->proximo; // atual recebe o endereco do primeiro "n�" da lista

	while (atual->elemento < pElemento) {
		anterior = atual;
		atual = atual->proximo;
	}

	if (atual != cabeca && atual->elemento == pElemento) {
		retorno = atual;
	}
	return retorno;
}


/*
Fun��o: Inserir
Par�metros:
- pElemento: Elemento a ser inserido
Descri��o: Permite inserir elementos em uma lista simplesmente encadeada ordenada.
*/
void inserir(int pElemento) {
	TipoNo *novoNo, *retornoBusca, *anterior, *atual;
	novoNo = cria_no();
	novoNo->elemento = pElemento;

	// se a lista estiver vazia entao sera o primeiro elemento a ser inserido
	if (is_lista_vazia()) {
		cabeca->proximo = novoNo;
		novoNo->proximo = cabeca;
		printf("Elemento inserido no endereco %p.\n", novoNo);
	}
	else {
		// Faz a busca primeiro
		retornoBusca = busca_circ(pElemento);
		if (retornoBusca != NULL) {
			printf("O elemento %d ja existe na lista!\n", pElemento);
		}
		else {
			anterior = cabeca;
			atual    = cabeca->proximo;
			while (atual->elemento < pElemento) {
				anterior = atual;
				atual = atual->proximo;
			}
			novoNo->proximo = anterior->proximo;
			anterior->proximo = novoNo;
			printf("Elemento inserido no endereco %p.\n", novoNo);
		}
	}
}


// Esta fun��o remove o elemento passado no par�metro.
void remover(int pElemento) {
	TipoNo *tempNo = NULL, *retornoBusca = NULL, *aux;

	retornoBusca = busca_circ(pElemento);
	aux          = cabeca->proximo;
	if (retornoBusca != NULL) {
		while (aux->proximo != retornoBusca) {
			aux = aux->proximo;
		}
		// ajustando ponteiros
		aux->proximo = retornoBusca->proximo;
		free(retornoBusca);
		printf("Elemento %d removido com sucesso!\n\n", pElemento);
		imprime_lista();

	} else {
			printf("O elemento informado nao existe na lista!\n");
	}
}

void exibe_menu() {
	int opcao_menu = -1;
	int elemento   = -1;

	cria_lista_vazia();

	while (opcao_menu != 4) {
		exibe_cabecalho();
		printf("\n-------> LISTA SIMPLESMENTE ENCADEADA CIRCULAR ORDENADA\n");
		printf("1 - Inserir na lista.\n");
		printf("2 - Remover da lista.\n");
		printf("3 - Imprimir lista.\n");
		printf("4 - sair\n");
		printf("Informe uma opcao: ");
		scanf("%d", &opcao_menu);
		switch (opcao_menu) {
		case 1:
			fflush(stdin);
			printf("Informe o elemento a ser inserido: ");
			scanf("%d", &elemento);
			inserir(elemento);
			printf("\nPressione qualquer tecla para continuar...");
		//	getch();
		//	clear_screen();
		break;

		case 2:
			if (!is_lista_vazia()) {
				imprime_lista();
				printf("\nQual elemento deseja remover? ");
				scanf("%d", &elemento);
				remover(elemento);
			} else {
				printf("A lista esta vazia!\n");
			}
			printf("\nPressione qualquer tecla para continuar...");
		//	getch();
		//	clear_screen();
			break;

		case 3:
			imprime_lista();
		//	getch();
		//	clear_screen();
			break;

		case 4:
			printf("\nPressione qualquer tecla para terminar o programa...");
		//	getch();
			break;

		default:
			printf("\nOpcao invalida!\n");
			printf("\nPressione qualquer tecla para continuar...\n");
	//		getch();
	//		clear_screen();
			break;
		}
	}
}

int main() {
	exibe_menu();
	return 0;
}
