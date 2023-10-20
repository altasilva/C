#include<stdio.h>

void asteriscos(int n){
  if(n==1)
    printf(("*\n"));
  else{
    asteriscos(n-1);
    for (int i=0;i<n;i++)
      printf(("\n*"));
  }
}
int main(){
  int n;
  printf("Entre com o valor de n: ");
  scanf("%d",&n);
  asteriscos(n);
  return 0;
}
