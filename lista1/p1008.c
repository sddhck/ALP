//SUBMISSÃO # 48203441
//Submissão: 17/03/2026 19:07:06

#include <stdio.h>

int main() {

    int number, workhours;
    double hourgain, monthsalary;

    scanf("%d", &number);
    scanf("%d", &workhours);
    scanf("%lf", &hourgain);

    monthsalary = workhours * hourgain;

    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %0.2lf\n", monthsalary);
}