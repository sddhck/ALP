//SUBMISSÃO # 48761886
//Submissão: 27/04/2026 13:04:34

#include <stdio.h>
 
int main() {
 
    int numero, posmaior, position;

    for(int pos = 1; pos <= 100; pos++){
        scanf("%d", &numero);
        if(pos == 1){
            posmaior = numero;
            position = pos;
        }
        else if(numero > posmaior){
            posmaior = numero;
            position = pos;
        }
    }

    printf("%d\n", posmaior);
    printf("%d\n", position);
 
    return 0;
}