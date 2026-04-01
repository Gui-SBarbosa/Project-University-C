#include <stdio.h>

int main() {
    int leituras[] = {45, 12, 78, 33, 90, 21, 56, 67};
    int busca, verificacoes = 0;

    printf("leitura para verificar: ");
    scanf("%d", &busca);

    for (int i = 0; i < 8; i++) {
        verificacoes++;
        if (leituras[i] == busca) {
            printf("leitura %d encontrada\n", busca);
            break;
        }
    }
    printf("total de verificacoes realizadas: %d\n", verificacoes);

    return 0;
}

