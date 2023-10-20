//busca binaria

#include<stdio.h>
#include<math.h>

void main()
{
  int v[]={1,2,3,4,5,6,7,8,9,10};
  int i, f, n, m;
  double meio;
  i=0;
  f=9;
  meio=floor((i+f)/2);
  m=(int)meio;
  printf("Digite um numero a ser localizado");
  scanf("%d", &n);
  while (i <= f)
  {
    if(v[m]==n)
    {
      printf("O numero esta na posicao %d\n",m );
    }
    else if (v[m]<n)
    {
      i = i+1;
    }//else if
    else{
      i=i-1;
    }//else
  }//while
}//main
