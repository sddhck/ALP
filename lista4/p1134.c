//SUBMISSÃO # 48597798
//Submissão: 14/04/2026 19:04:51

#include <stdio.h>
 
int main() {
 
    int gas = 0, diesel = 0, alcohol = 0, numero = 0;

    do
    {
        scanf("%d", &numero);

        if (numero == 1)
        {
            alcohol = alcohol + 1;
        }

        if (numero == 2)
        {
            gas = gas + 1;
        }

        if (numero == 3)
        {
            diesel = diesel + 1;
        }

        if (numero == 4)
            break;
        
    } while (1);

    puts("MUITO OBRIGADO");
    printf("Alcool: %d\n", alcohol);
    printf("Gasolina: %d\n", gas);
    printf("Diesel: %d\n", diesel);
    
 
    return 0;
}