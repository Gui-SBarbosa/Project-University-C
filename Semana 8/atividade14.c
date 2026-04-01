#include <stdio.h>

int main() {
    long long cpfs[] = {11122233300, 22233344400, 33344455500, 44455566600, 55566677700};
    long long busca;
    int ini = 0, fim = 4, meio, etapas = 0;

    printf("digite o CPF (so numeros): ");
    scanf("%lld", &busca);

    while (ini <= fim) {
        etapas++;
        meio = (ini + fim) / 2;
        if (cpfs[meio] == busca) {
            printf("CPF cadastrado na posicao %d, etapas da busca: %d\n", meio, etapas);
            return 0;
        }
        if (cpfs[meio] < busca) {
            ini = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    printf("CPF nao encontrado, etapas realizadas: %d\n", etapas);
    return 0;
}