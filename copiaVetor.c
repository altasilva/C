#include<stdio.h>

void listavetor(int vet[]){
  
  for(int i=0; i<5; i++){
    vet[i]=i+1;
  }

}

void main(){
  int vetor[5];
  listavetor(vetor);

   for(int i=0; i<5; i++){	
    printf("Vetor: %d\n", vetor[i]);
  }

  

}


