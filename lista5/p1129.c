//SUBMISSÃO # 48690561
//Submissão: 21/04/2026 17:06:26

#include <stdio.h>
 
int main() {
 
   int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        
        for (int i = 0; i < n; i++) {
            int a, b, c, d, e;
            int marcados = 0;

   scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

   if (a <= 127) {
    marcados = marcados + 1;
   }
    if (b <= 127) {
    marcados = marcados + 1;
    }
    if (c <= 127) {
    marcados = marcados + 1;
    }
    if (d <= 127) {
    marcados = marcados + 1;
    }
    if (e <= 127) {
    marcados = marcados + 1;
    }

    if (marcados != 1) {
        printf("*\n");
    } 

    if (marcados == 1 && a <= 127) {
        printf("A\n");
    }
    if (marcados == 1 && b <= 127) {
        printf("B\n");
    }
    if (marcados == 1 && c <= 127) {
        printf("C\n");
    }
    if (marcados == 1 && d <= 127) {
        printf("D\n");
    }
    if (marcados == 1 && e <= 127) {
        printf("E\n");
    } } }

 
    return 0;
}