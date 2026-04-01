#include <stdio.h>

#define TAMANHO 7

int main()
{
    int vetor[TAMANHO] = {11, 22, 33, 44, 55, 66, 77};
    int busca;
    int inicio = 0;
    int fim = TAMANHO - 1;
    int meio;
    int comparacoes = 0;
    int passo = 1;

    printf("Vetor: ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    printf("Digite o valor para buscar: ");
    scanf("%d", &busca);

    printf("\n\tINICIANDO BUSCA BINARIA\n");
    printf("Buscando valor: %d\n\n", busca);

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        comparacoes++;

        printf("Passo %d:\n", passo);
        printf("  Inicio = %d (indice %d) - valor: %d\n", inicio, inicio, vetor[inicio]);
        printf("  Fim    = %d (indice %d) - valor: %d\n", fim, fim, vetor[fim]);
        printf("  Meio   = %d (indice %d) - valor: %d\n", meio, meio, vetor[meio]);
        printf("  Comparando %d com %d\n", busca, vetor[meio]);

        if (vetor[meio] == busca)
        {
            printf("\n>>> ENCONTRADO! <<<\n");
            printf("Valor %d encontrado no indice %d\n", busca, meio);
            printf("Total de comparacoes: %d\n", comparacoes);
            return 0;
        }
        else if (busca < vetor[meio])
        {
            printf("  %d é MENOR que %d\n", busca, vetor[meio]);
            printf("  -> Buscar na metade ESQUERDA\n");
            fim = meio - 1;
        }
        else
        {
            printf("  %d é MAIOR que %d\n", busca, vetor[meio]);
            printf("  -> Buscar na metade DIREITA\n");
            inicio = meio + 1;
        }

        printf("\n");
        passo++;
    }

    printf("\n\tBUSCA ENCERRADA\n");
    printf("Valor %d NAO ENCONTRADO no vetor\n", busca);
    printf("Ponto de encerramento:\n");
    printf("  inicio = %d\n", inicio);
    printf("  fim = %d\n", fim);
    printf("  Condicao inicio > fim ( %d > %d )\n", inicio, fim);
    printf("Total de comparacoes: %d\n", comparacoes);

    return 0;
}