//SUBMISSÃO # 48770769
//Submissão: 27/04/2026 20:53:41

#include <stdio.h>

int main() {
    int N, X, Y, temp;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int soma = 0; 
        scanf("%d %d", &X, &Y);

    
        if (X > Y) {
            temp = X;
            X = Y;
            Y = temp;
        }

    
        for (int j = X + 1; j < Y; j++) {
            if (j % 2 != 0) { 
                soma += j;
            }
        }
        
        printf("%d\n", soma);
    }

    return 0;
}