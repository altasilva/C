//busca sequencial
#include <stdio.h>

void main()
{
  int x;

  int v[]={1,2,3,4,5};

  printf("\nDigite um numero inteiro para ser localizado: ");
  scanf("%x", &x);
  for (int i=0; i<5; i++)
  {
    if (v[i]==x)
    {
      printf("O numero esta na posicao %d.\n", i);
    }//if
  }//for
}//main
