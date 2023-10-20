//fatorial

#include <stdio.h>

int fatorial(int n)
{
  int fat;
  if(n==0 || n==1){
    fat=1;
  }//if
  else
  {
    fat = n * fatorial(n-1);
  }//else
return fat;
}//fatotial

void main(){
  int n;
  printf("\nDeseja calcular o fatorial de qual número?\n");
  scanf("%d",&n);
  printf("O fatorial de %d é: %d\n",n,fatorial(n));
}//main
