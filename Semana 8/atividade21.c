#include <stdio.h>

int main()
{
    int historico[] = {321, 105, 876, 432, 210, 654, 999, 111};
    int tamanho = 8;

    int busca;
    int posicao = -1;
    int comparacoes = 0;

    printf("Digite o ID da pagina que deseja buscar: ");
    scanf("%d", &busca);

    for (int i = 0; i < tamanho; i++)
    {
        comparacoes++;
        if (historico[i] == busca)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        printf("Pagina %d ENCONTRADA!\n", busca);
        printf("Posicao: %d (indice %d do vetor)\n", posicao + 1, posicao);
    }
    else
    {
        printf("Pagina %d NAO ENCONTRADA no historico.\n", busca);
    }
    printf("Numero de comparacoes realizadas: %d\n", comparacoes);

    return 0;
}