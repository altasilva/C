#include<stdio.h>
#include<stdlib.h>

typedef struct no celula;

struct no{
    int chave;
    struct no *prox;
};

celula* criar_celula(){
  celula *no = (celula*)malloc(sizeof(celula));
  return no;
}

celula* inserir_elemento_inicio(int x, celula *ptlista){
  celula *no=criar_celula();
  no->chave=x;

  if(ptlista==NULL){
    no->prox=NULL;
    ptlista=no;
  }else{
    no->prox=ptlista;
    ptlista=no;
  }//else
  return ptlista;
}//inserir_elemento_inicio

celula* inserir_elemento_fim(int x, celula *ptlista){
  celula *no=criar_celula();
  no->chave=x;

  if(ptlista==NULL){
    no->prox=NULL;
    ptlista=no;
  }else{
    celula* aux=ptlista;
      while(aux->prox!=NULL){
        aux=aux->prox;
      }//while
      no->prox=NULL;
      aux->prox=no;
  }//else
  return ptlista;
}//inserir_elemento_fim


void imprimir_lse(celula* ptlista){
  celula* aux = ptlista;
  while (aux!=NULL){
    printf("%d -> ",aux->chave);
    aux=aux->prox;
  }//while
printf("\n\n\n");
}//imprimir_lse


int main()
{
  int op,n;
  celula *p = NULL;
  system("clear");
  loop:
  printf("\nDigite uma das opcoes abaixo: \n");
  printf("(1)-Inserir elemento na primeira posicao da lista.\n");
  printf("(2)-Inserir elemento na ultima posicao da lista.\n");
  printf("(3)-Imprimir elementos.\n");
  printf("(0)-sair.\n");
  scanf("%d",&op);
  switch(op)
  {
    case 1:
      printf("\n\n");
      printf("Digite um numero a ser inserido.\n");
      scanf("%d",&n);
      p=inserir_elemento_inicio(n,p);
      system("clear");
      goto loop;
    case 2:
      printf("\n\n");
      printf("Digite um numero a ser inserido.\n");
      scanf("%d",&n);
      p=inserir_elemento_fim(n,p);
      system("clear");
      goto loop;
    case 3:
      system("clear");
      printf("\n\n");
      printf("Imprimindo: ");
      imprimir_lse(p);
      goto loop;
    case 0:
      break;
  }//switch
  return 0;
}//main
