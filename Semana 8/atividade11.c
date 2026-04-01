#include <stdio.h>

int main() {
    int pedidos[] = {903, 112, 457, 221, 678, 345, 789, 150};
    int busca, comparacoes = 0, encontrado = -1;

    printf("Digite o codigo do pedido: ");
    scanf("%d", &busca);

    for (int i = 0; i < 8; i++) {
        comparacoes++;
        if (pedidos[i] == busca) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1)
        printf("Pedido encontrado na posicao %d. Comparacoes: %d\n", encontrado, comparacoes);
    else
        printf("Pedido nao encontrado, foram feitas %d comparacoes.\n", comparacoes);

    return 0;
}