//SUBMISSÃO # 48690803
//Submissão: 21/04/2026 17:24:58

#include <stdio.h>
 
int main() {
 
    int n = 0;
    while (scanf("%d", &n) == 1 && n != 0) {
    int maria = 0, joao = 0;

    for (int i = 0; i < n; i++) {
        int vencedor = 0;
        scanf("%d", &vencedor);
    if (vencedor == 0) {
        maria++;
    }
    if (vencedor == 1) {
        joao++;
    }
    } 

    printf("Mary won %d times and John won %d times\n", maria, joao);
}
 
    return 0;
}