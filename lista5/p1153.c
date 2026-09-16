//SUBMISSÃO # 48689919
//Submissão: 21/04/2026 16:20:32

#include <stdio.h>
 
int main() {
 
    int N, fatorial = 1;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        fatorial = fatorial * i;
    }
    printf("%d\n", fatorial);
 
    return 0;
}