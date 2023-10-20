//fila atraves de lista encadeada
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

celula *inicio, *fim;

void cria_fila()
{
  inicio=(celula*)malloc(sizeof(celula)); //reserva, dinamicamente, espaço na memoria
  inicio->prox = NULL;
  fim=inicio;
}//criar_fila

void imprime_fila()
{
  if(inicio->prox==NULL)
  {
    printf("\nA fila nao possui elementos.\n\n\n");
  }//if
  else
  {
    system("clear");
    printf("\nElementos da fila:\n");
    printf("==================\n");
    for(celula *p=(inicio->prox); p!=NULL; p=p->prox)
    {
      printf("%d", p->conteudo);
    }//for
    printf("\n\n\n");
  }//else
}//imprime_fila

void insere(int y)
{
  celula *novo;
  novo=(celula*)malloc(sizeof(celula));
  novo->conteudo=y;
  novo->prox = fim->prox;
  fim->prox=novo;
  fim=novo;
}//insere

int retira()
{
  if(inicio->prox==NULL)
  {
    printf("\nA fila nao possui elementos a serem removidos.\n\n\n");
    return 0;
  }//if
  else
  {
    int x;
    celula *p;
    p=inicio->prox;
    x=p->conteudo;
    inicio->prox=p->prox;
    free(p);
    return x;
  }//else
}//remove

/*
Aqui começa o metodo principal. Nele optei por utilizar o comando "switch/case"
onde o usuario tem 4 opçoes para escolher. Quando ele digitar 0 ele sai da
estrutura. O comando "goto" volta na palavra "loop:" sendo assim o algoritmo
so sai do laço "switch/case" quando digitar 0. Assim podemos inserir e
remover quantos elementos desejarmos além de imprimir na tela a fila. Caso
nao haja elementos na fila uma mensagem aparece dizendo que a fila esta vazia.
*/

int main()
{
  int op,n;
  cria_fila();
  system("clear");
  loop:
  printf("\nDigite uma das opcoes abaixo: \n");
  printf("(1)-inserir elementos.\n");
  printf("(2)-remover elementos.\n");
  printf("(3)-imprimir elementos.\n");
  printf("(0)-sair.\n");
  scanf("%d",&op);
  switch(op)
  {
    case 1:
      printf("Digite um numero a ser inserido.\n");
      scanf("%d",&n);
      insere(n);
      system("clear");
      goto loop;
    case 2:
      system("clear");
      retira();
      goto loop;
    case 3:
      imprime_fila();
      goto loop;
    case 0:
      break;
  }//switch
}//main
