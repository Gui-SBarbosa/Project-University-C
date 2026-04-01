#include <stdio.h>

int main()
{
    int vetor[] = {77, 12, 89, 34, 56, 23, 90};
    int tamanho = 7;

    int busca;
    int posicao = -1;
    int comparacoes = 0;

    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &busca);

    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    for (int i = 0; i < tamanho; i++)
    {
        comparacoes++;
        printf("Verificando posicao %d (indice %d): valor %d\n", i + 1, i, vetor[i]);

        if (vetor[i] == busca)
        {
            posicao = i;
            printf(">>> VALOR ENCONTRADO! <<<\n");
            break;
        }
        printf("  %d é diferente de %d, continuando...\n", vetor[i], busca);
        printf("\n");
    }

    if (posicao != -1)
    {
        printf("Valor %d ENCONTRADO!\n", busca);
        printf("Posicao: %d (indice %d do vetor)\n", posicao + 1, posicao);
    }
    else
    {
        printf("Valor %d NAO ENCONTRADO no vetor.\n", busca);
    }
    printf("Numero de comparacoes realizadas: %d\n", comparacoes);

    return 0;
}