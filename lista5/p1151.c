//SUBMISSÃO # 48689791
//Submissão: 21/04/2026 16:10:53

#include <stdio.h>
 
int main() {
 
    int N, atual = 1, antes = 0, proximo;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        if (i == N) {
            printf("%d\n", antes);
        }else {
            printf("%d ", antes);
        }
        

        proximo = antes + atual;
        antes = atual;
        atual = proximo;

    }
 
    return 0;
}