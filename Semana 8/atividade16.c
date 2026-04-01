#include <stdio.h>

int main() {
    int votos[] = {3, 1, 4, 2, 5, 3, 2, 1, 4};
    int candidato, contagem = 0;

    printf("consultar votos do candidato (1-5): ");
    scanf("%d", &candidato);

    for (int i = 0; i < 9; i++) {
        if (votos[i] == candidato) contagem++;
    }

    printf("o candidato %d recebeu %d votos.\n", candidato, contagem);
    return 0;
}