#include <stdio.h>

int main()
{
    int vetor[] = {5, 15, 25, 35, 45, 55};
    int tamanho = 6;

    int novo_valor;
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    int posicao_insercao = -1;
    int iteracao = 1;

    printf("Digite o novo valor a ser inserido: ");
    scanf("%d", &novo_valor);

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        printf("Iteracao %d:\n", iteracao);
        printf("  Inicio = %d (indice %d) - valor: %d\n", inicio, inicio, vetor[inicio]);
        printf("  Meio   = %d (indice %d) - valor: %d\n", meio, meio, vetor[meio]);
        printf("  Fim    = %d (indice %d) - valor: %d\n", fim, fim, vetor[fim]);

        if (vetor[meio] == novo_valor)
        {
            // Valor ja existe, inserir na mesma posicao
            posicao_insercao = meio;
            printf("\n>>> Valor igual ao elemento do meio! <<<\n");
            printf(">>> Posicao de insercao: indice %d <<<\n", posicao_insercao);
            break;
        }
        else if (novo_valor < vetor[meio])
        {
            printf("  %d é MENOR que %d -> buscar na metade ESQUERDA\n", novo_valor, vetor[meio]);
            fim = meio - 1;
        }
        else
        {
            printf("  %d é MAIOR que %d -> buscar na metade DIREITA\n", novo_valor, vetor[meio]);
            inicio = meio + 1;
        }

        printf("\n");
        iteracao++;
    }

    if (posicao_insercao == -1)
    {
        posicao_insercao = inicio;
        printf("\n>>> Loop encerrado com inicio > fim <<<\n");
        printf(">>> Posicao de insercao: indice %d <<<\n", posicao_insercao);
    }

    printf("Vetor atual: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Novo valor: %d\n", novo_valor);
    printf("Posicao correta para insercao: indice %d\n", posicao_insercao);

    printf("Vetor com insercao no indice %d:\n", posicao_insercao);
    for (int i = 0; i < tamanho; i++)
    {
        if (i == posicao_insercao)
        {
            printf("[%d] ", novo_valor);
        }
        printf("%d ", vetor[i]);
    }
    if (posicao_insercao == tamanho)
    {
        printf("[%d] ", novo_valor);
    }
    printf("\n");

    return 0;
}