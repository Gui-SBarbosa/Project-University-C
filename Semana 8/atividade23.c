#include <stdio.h>

int main()
{
    int produtos[] = {10, 25, 10, 30, 45, 25, 60, 10};
    int tamanho = 8;

    int busca;
    int posicoes[10];
    int total_encontradas = 0;
    int comparacoes = 0;

    printf("Digite o ID do produto que deseja buscar: ");
    scanf("%d", &busca);

    for (int i = 0; i < tamanho; i++)
    {
        comparacoes++;
        if (produtos[i] == busca)
        {
            posicoes[total_encontradas] = i;
            total_encontradas++;
        }
    }

    printf("Produto buscado: %d\n", busca);
    printf("Numero de comparacoes realizadas: %d\n", comparacoes);

    if (total_encontradas > 0)
    {
        printf("\nO produto foi encontrado %d vez(es):\n", total_encontradas);
        printf("Posicoes (indices do vetor): ");
        for (int i = 0; i < total_encontradas; i++)
        {
            printf("%d ", posicoes[i]);
        }
        printf("\n");

        printf("\nDetalhamento:\n");
        for (int i = 0; i < total_encontradas; i++)
        {
            printf("  Ocorrencia %d: indice %d (posicao %d do vetor)\n",
                   i + 1, posicoes[i], posicoes[i] + 1);
        }
    }
    else
    {
        printf("\nProduto NAO ENCONTRADO no vetor.\n");
    }

    return 0;
}