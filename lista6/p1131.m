//SUBMISSÃO # 48762523
//Submissão: 27/04/2026 14:01:20

#include <stdio.h>

int main() {
    int golsInter, golsGremio;
    int vitoriainter = 0, vitoriagremio = 0, empates = 0;
    int totalGrenais = 0;
    int opcao;

    do {

        scanf("%d %d", &golsInter, &golsGremio);
        totalGrenais++;


        if (golsInter > golsGremio) {
            vitoriainter++;
        } else if (golsGremio > golsInter) {
            vitoriagremio++;
        } else {
            empates++;
        }

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &opcao);

    } while (opcao == 1);

    printf("%d grenais\n", totalGrenais);
    printf("Inter:%d\n", vitoriainter);
    printf("Gremio:%d\n", vitoriagremio);
    printf("Empates:%d\n", empates);

    if (vitoriainter > vitoriagremio) {
        printf("Inter venceu mais\n");
    } else if (vitoriagremio > vitoriainter) {
        printf("Gremio venceu mais\n");
    } else {
        printf("Nao houve vencedor\n");
    }

    return 0;
}