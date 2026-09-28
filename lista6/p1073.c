//SUBMISSÃO # 48761954
//Submissão: 27/04/2026 13:11:57

#include <stdio.h>
 
int main() {
 
    int leitura;
    scanf("%d", &leitura);

    for(int i = 1; i <= leitura; i++) {
        if(i % 2 == 0){
            printf("%d^2 = %d\n", i, i*i);
        }
    }
 
    return 0;
}