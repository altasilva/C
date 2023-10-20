//pilha atraves de lista encadeada
//Autor: Alex Tavares Silva
//Professor: Ricardo Sousa


#include<stdio.h>
#include<stdlib.h>

struct no
{
  int conteudo;
  struct no *prox;
};

typedef struct no celula;

celula *tp;

void cria_pilha()
{
  tp = (celula*)malloc(sizeof(celula));//reserva, dinamicamente, espaço na memoria
  tp -> prox = NULL;
}//criar_pilha

void imprime_pilha()
{
  if(tp->prox==NULL)
  {
    printf("\nA pilha nao possui elementos.\n\n\n");
  }//if
  else
  {
    printf("\nElementos da pilha: \n");
    printf("====================\n");
      for (celula *p = (tp->prox); p!=NULL; p=p->prox)
      {
        printf("%d",p->conteudo);
        printf ("\n");
      }
      printf ("\n");
  }//else
}//imprime_pilha

void empilha(int y)
{
  celula *novo;
  novo=(celula*)malloc(sizeof(celula));
  novo->conteudo=y;
  novo->prox=tp->prox;
  tp->prox = novo;
}//empilha

int desempilha()
{
  if(tp->prox == NULL)
  {
    printf("A pilha nao possui elementos a serem removidos.");
  }//if
  else
  {
    int x;
    celula *p;
    p=tp->prox;
    x=p->conteudo;
    tp->prox=p->prox;
    free(p);
    return x;
  }//else
}//desempilha


/*
Aqui começa o metodo principal. Nele optei por utilizar o comando "switch/case"
onde o usuario tem 4 opçoes para escolher. Quando ele digitar 0 ele sai da
estrutura. O comando "goto" volta na palavra "loop:" sendo assim o algoritmo
so sai do laço "switch/case" quando digitar 0. Assim podemos empilhar e
desempilhar quantos elementos desejarmos além de imprimir na tela a pilha.
Optei por colocar em formato de pilha por uma questao de praticidade.
*/

void main()
{
  int op,n;
  cria_pilha();
  system("clear");
  loop:
  printf("\nDigite uma das opcoes abaixo: \n");
  printf("(1)-empilhar elementos.\n");
  printf("(2)-desempilhar elementos.\n");
  printf("(3)-imprimir elementos.\n");
  printf("(0)-sair.\n");
  scanf("%d",&op);
  switch(op)
  {
    case 1:
      printf("Digite um numero a ser empilhado.\n");
      scanf("%d",&n);
      empilha(n);
      system("clear");
      goto loop;
    case 2:
      desempilha();
      system("clear");
      goto loop;
    case 3:
      imprime_pilha();
      goto loop;
    case 0:
      break;
  }//switch
}//main
