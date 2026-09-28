//SUBMISSÃO # 48688181
//Submissão: 21/04/2026 14:09:12

#include <stdio.h>

int main() {

    double a, b, media;
    int c;
   
    do {
        while (1) {
        scanf("%lf", &a);
    if (a >= 0 && a <= 10){
        break;
    } else {
        printf("nota invalida\n");
    } }

    while (1) {
        scanf("%lf", &b);
    if (b >= 0 && b <= 10){
        break;
    } else {
        printf("nota invalida\n");
    } }

    media = (a + b) / 2;
    printf("media = %.2lf\n", media);

    do {
        printf("novo calculo (1-sim 2-nao)\n");
        scanf("%d", &c);
    } while (c != 1 && c != 2);
    
} while (c == 1);



    return 0;
}