//SUBMISSÃO # 48503272
//Submissão: 07/04/2026 22:10:54

#include <stdio.h>
 
int main() {
 
   double income, imposto, tarifado;

   scanf("%lf", &income);

   if (income > 0.00 && income < 2000.01) {
    imposto = 0.00;
    tarifado = 0.00;
    printf("Isento\n");
    
   }

   if (income > 2000.00 && income < 3000.01) {
    tarifado = income - 2000.00;
    imposto = tarifado * 0.08;
    printf("R$ %.2lf\n", imposto);
   }

   if (income > 3000.00 && income < 4500.01) {
    tarifado = income - 3000.00;
    imposto = (tarifado * 0.18) + 80;
    printf("R$ %.2lf\n", imposto);
   }

   if (income > 4500.00) {
    tarifado = income -4500.00;
    imposto = (tarifado * 0.28) + 350;
    printf("R$ %.2lf\n", imposto);
   }
 
    return 0;
}