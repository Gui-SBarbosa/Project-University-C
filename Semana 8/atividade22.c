#include <stdio.h>

int main()
{
    int transacoes[] = {1001, 1020, 1055, 1100, 1200, 1300, 1500};
    int tamanho = 7;

    int busca;
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    int posicao = -1;
    int iteracao = 1;

    printf("Digite o codigo da transacao que deseja buscar: ");
    scanf("%d", &busca);

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        printf("Iteracao %d:\n", iteracao);
        printf("  Inicio = %d (indice %d) - valor: %d\n", inicio, inicio, transacoes[inicio]);
        printf("  Meio   = %d (indice %d) - valor: %d\n", meio, meio, transacoes[meio]);
        printf("  Fim    = %d (indice %d) - valor: %d\n", fim, fim, transacoes[fim]);

        if (transacoes[meio] == busca)
        {
            posicao = meio;
            printf("\n\tENCONTRADO na iteracao %d!\n", iteracao);
            break;
        }
        else if (busca < transacoes[meio])
        {
            printf("  %d é MENOR que %d -> buscar na metade ESQUERDA\n", busca, transacoes[meio]);
            fim = meio - 1;
        }
        else
        {
            printf("  %d é MAIOR que %d -> buscar na metade DIREITA\n", busca, transacoes[meio]);
            inicio = meio + 1;
        }

        printf("\n");
        iteracao++;
    }

    if (posicao != -1)
    {
        printf("Codigo %d ENCONTRADO!\n", busca);
        printf("Posicao: %d (indice %d do vetor)\n", posicao + 1, posicao);
    }
    else
    {
        printf("Codigo %d NAO ENCONTRADO na lista.\n", busca);
    }

    return 0;
}