#include <stdio.h>

#define TAMANHO 8

int buscaIterativa(int vetor[], int tamanho, int busca)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == busca)
        {
            return meio;
        }
        else if (busca < vetor[meio])
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return -1;
}

int buscaRecursiva(int vetor[], int inicio, int fim, int busca)
{
    if (inicio > fim)
    {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == busca)
    {
        return meio;
    }
    else if (busca < vetor[meio])
    {
        return buscaRecursiva(vetor, inicio, meio - 1, busca);
    }
    else
    {
        return buscaRecursiva(vetor, meio + 1, fim, busca);
    }
}

int main()
{
    int vetor[TAMANHO] = {2, 4, 6, 8, 10, 12, 14, 16};
    int busca;
    int posicao;

    printf("Vetor: ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    printf("Digite o valor para buscar: ");
    scanf("%d", &busca);

    posicao = buscaIterativa(vetor, TAMANHO, busca);
    printf("\n\tBUSCA ITERATIVA\n");
    if (posicao != -1)
    {
        printf("Valor %d encontrado no indice %d\n", busca, posicao);
    }
    else
    {
        printf("Valor %d nao encontrado\n", busca);
    }

    // Testa recursiva
    posicao = buscaRecursiva(vetor, 0, TAMANHO - 1, busca);
    printf("\n\tBUSCA RECURSIVA\n");
    if (posicao != -1)
    {
        printf("Valor %d encontrado no indice %d\n", busca, posicao);
    }
    else
    {
        printf("Valor %d nao encontrado\n", busca);
    }

    printf("\n\tCOMPARACAO\n");
    printf("Legibilidade:\n");
    printf("  Iterativa: Fluxo claro com loop, facil de entender\n");
    printf("  Recursiva: Codigo mais curto, mas requer entender recursao\n");
    printf("\nUso de memoria:\n");
    printf("  Iterativa: O(1) - usa apenas variaveis locais\n");
    printf("  Recursiva: O(log n) - cada chamada ocupa espaco na pilha\n");
    printf("  Para 8 elementos: recursiva usa ate 4 niveis de pilha\n");

    return 0;
}