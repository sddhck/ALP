//SUBMISSÃO # 49258343
//Submissão: 08/06/2026 17:41:34

#include <stdio.h>

int menor(int A, int B) {
  if(A < B){
    return A;
  } else
    return B;
}

int main(void) {
  int N;

  while(scanf("%d", &N) != EOF) {
    int botasDireita[61] = {0}, botasEsquerda[61] = {0};

    int tamanho;
    char lado;

    for(int i = 0; i < N; i++) {
      scanf("%d %c", &tamanho, &lado);
      if(lado == 'D'){
        botasDireita[tamanho]++;
      }
      if(lado == 'E'){
        botasEsquerda[tamanho]++;
      }
    }
      int totalPares = 0;
      for(int i = 30; i <= 60; i++){
        totalPares = totalPares + menor(botasDireita[i], botasEsquerda[i]);
      }
    
    printf("%d\n", totalPares);
  }
  return 0;
}