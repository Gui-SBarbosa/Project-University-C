#include <stdio.h>

int main() {
    int filmes[] = {501, 123, 876, 234, 654, 345, 999};
    int busca, verificado = 0, i;

    printf("ID do filme: ");
    scanf("%d", &busca);

    for (i = 0; i < 7; i++) {
        verificado++;
        if (filmes[i] == busca) {
            printf("filme encontrado na posicao %d.\n", i);
            return 0;
        }
    }
    printf("filme nao encontrado. foram verificados %d elementos.\n", verificado);
    return 0;
}