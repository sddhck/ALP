//SUBMISSÃO # 48767431
//Submissão: 27/04/2026 17:33:12

#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        printf("%d %d %d\n", i, i * i, i * i * i);
        printf("%d %d %d\n", i, (i * i) + 1, (i * i * i) + 1);
    }

    return 0;
}