//SUBMISSÃO # 48501993
//Submissão: 07/04/2026 21:21:02

#include <stdio.h>
 
int main() {
 
  int A, B, C;

  scanf("%d %d %d", &A, &B, &C);

  if (A < B && B < C) {
    printf("%d\n", A);
    printf("%d\n", B);
    printf("%d\n", C);
  }

  if (A < C && C < B) {
    printf("%d\n", A);
    printf("%d\n", C);
    printf("%d\n", B);
  }

  if (B < A && A < C) {
    printf("%d\n", B);
    printf("%d\n", A);
    printf("%d\n", C);
  }

  if (B < C && C < A) {
    printf("%d\n", B);
    printf("%d\n", C);
    printf("%d\n", A);
  }

  if (C < A && A < B) {
    printf("%d\n", C);
    printf("%d\n", A);
    printf("%d\n", B);
  }

  if (C < B && B < A) {
    printf("%d\n", C);
    printf("%d\n", B);
    printf("%d\n", A);
  }

  printf("\n");

  printf("%d\n", A);
  printf("%d\n", B);
  printf("%d\n", C);
 
    return 0;
}