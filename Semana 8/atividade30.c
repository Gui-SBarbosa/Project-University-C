#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_PEQUENO 10
#define TAMANHO_GRANDE 1000000

int buscaSequencial(int vetor[], int tamanho, int busca, int *comparacoes)
{
    *comparacoes = 0;
    for (int i = 0; i < tamanho; i++)
    {
        (*comparacoes)++;
        if (vetor[i] == busca)
        {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int vetor[], int tamanho, int busca, int *comparacoes)
{
    *comparacoes = 0;
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        (*comparacoes)++;
        int meio = (inicio + fim) / 2;

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

int comparar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    srand(time(NULL));

    printf("=== ANALISE CRITICA DE ALGORITMOS ===\n\n");

    printf("AFIRMACAO I: 'A busca binaria sempre e mais rapida que a busca sequencial'\n\n");

    int vetorPequeno[TAMANHO_PEQUENO];
    for (int i = 0; i < TAMANHO_PEQUENO; i++)
    {
        vetorPequeno[i] = i * 10;
    }

    int busca = vetorPequeno[0];
    int comparacoesSeq, comparacoesBin;
    int pos;

    pos = buscaSequencial(vetorPequeno, TAMANHO_PEQUENO, busca, &comparacoesSeq);
    pos = buscaBinaria(vetorPequeno, TAMANHO_PEQUENO, busca, &comparacoesBin);

    printf("\tCenario 1 - Elemento no INICIO (vetor pequeno):\n");
    printf("  Busca sequencial: %d comparacoes\n", comparacoesSeq);
    printf("  Busca binaria:    %d comparacoes\n", comparacoesBin);
    printf("  Resultado: Busca sequencial FOI mais rapida!\n\n");

    int *vetorGrande = (int *)malloc(TAMANHO_GRANDE * sizeof(int));
    for (int i = 0; i < TAMANHO_GRANDE; i++)
    {
        vetorGrande[i] = i;
    }

    busca = vetorGrande[TAMANHO_GRANDE - 1]; // ultimo elemento
    pos = buscaSequencial(vetorGrande, TAMANHO_GRANDE, busca, &comparacoesSeq);
    pos = buscaBinaria(vetorGrande, TAMANHO_GRANDE, busca, &comparacoesBin);

    printf("\tCenario 2 - Elemento no FINAL (vetor grande):\n");
    printf("  Busca sequencial: %d comparacoes\n", comparacoesSeq);
    printf("  Busca binaria:    %d comparacoes\n", comparacoesBin);
    printf("  Resultado: Busca binaria FOI mais rapida!\n\n");

    printf("\tANALISE DA AFIRMACAO I:\n");
    printf("  Status: FALSA\n");
    printf("  Justificativa: A busca sequencial pode ser mais rapida que a binaria\n");
    printf("  quando o elemento buscado esta nas primeiras posicoes do vetor.\n");
    printf("  Exemplo: Para 10 elementos, sequencial faz 1 comparacao enquanto\n");
    printf("  binaria faz ate 4 comparacoes. A busca binaria so e mais eficiente\n");
    printf("  em media e para vetores grandes.\n\n");

    printf("\tAFIRMACAO II: 'A busca sequencial nao depende da ordenacao dos dados'\n\n");

    int vetorNaoOrdenado[] = {55, 23, 87, 12, 99, 34, 78, 45, 67, 88};
    int vetorOrdenado[] = {12, 23, 34, 45, 55, 67, 78, 87, 88, 99};
    int tamanho = 10;
    busca = 45;

    pos = buscaSequencial(vetorNaoOrdenado, tamanho, busca, &comparacoesSeq);
    printf("Vetor NAO ordenado:\n");
    printf("  Busca sequencial: %d comparacoes - encontrou no indice %d\n", comparacoesSeq, pos);

    pos = buscaSequencial(vetorOrdenado, tamanho, busca, &comparacoesSeq);
    printf("Vetor ORDENADO:\n");
    printf("  Busca sequencial: %d comparacoes - encontrou no indice %d\n\n", comparacoesSeq, pos);

    printf("\tANALISE DA AFIRMACAO II:\n");
    printf("  Status: VERDADEIRA\n");
    printf("  Justificativa: A busca sequencial percorre o vetor elemento por\n");
    printf("  elemento independentemente da ordem. Funciona tanto em vetores\n");
    printf("  ordenados quanto nao ordenados, pois nao faz nenhuma suposicao\n");
    printf("  sobre a organizacao dos dados.\n\n");

    printf("\tAFIRMACAO III: 'A busca binaria so funciona corretamente em dados ordenados'\n\n");

    printf("Teste com vetor NAO ordenado:\n");
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetorNaoOrdenado[i]);
    }
    printf("\n");

    busca = 45;
    pos = buscaBinaria(vetorNaoOrdenado, tamanho, busca, &comparacoesBin);
    printf("Buscando %d:\n", busca);
    printf("  Busca binaria: %d comparacoes\n", comparacoesBin);
    if (pos != -1)
    {
        printf("  Resultado: Encontrou no indice %d (ERRADO!)\n", pos);
    }
    else
    {
        printf("  Resultado: Nao encontrou (CORRETO nesse caso)\n");
    }

    busca = 12;
    pos = buscaBinaria(vetorNaoOrdenado, tamanho, busca, &comparacoesBin);
    printf("\nBuscando %d:\n", busca);
    printf("  Busca binaria: %d comparacoes\n", comparacoesBin);
    if (pos != -1)
    {
        printf("  Resultado: Encontrou no indice %d (PODE ESTAR ERRADO!)\n", pos);
        printf("  O valor %d existe no vetor, mas a busca binaria pode falhar\n", busca);
        printf("  porque o vetor nao esta ordenado.\n");
    }

    printf("\nTeste com vetor ORDENADO:\n");
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetorOrdenado[i]);
    }
    printf("\n");

    busca = 45;
    pos = buscaBinaria(vetorOrdenado, tamanho, busca, &comparacoesBin);
    printf("Buscando %d:\n", busca);
    printf("  Busca binaria: %d comparacoes\n", comparacoesBin);
    printf("  Resultado: Encontrou no indice %d (CORRETO!)\n\n", pos);

    printf("\tANALISE DA AFIRMACAO III:\n");
    printf("  Status: VERDADEIRA\n");
    printf("  Justificativa: A busca binaria depende da propriedade de ordenacao\n");
    printf("  para funcionar. Ela assume que se o valor do meio e maior que o\n");
    printf("  buscado, o valor so pode estar na metade esquerda. Em vetores\n");
    printf("  nao ordenados, essa premissa e falsa e o algoritmo pode falhar.\n\n");

    printf("=== RESUMO FINAL ===\n");
    printf("\n");
    printf("| Afirmacao | Status     | Justificativa                                      |\n");
    printf("|-----------|------------|----------------------------------------------------|\n");
    printf("| I         | FALSA      | Busca sequencial pode ser mais rapida quando        |\n");
    printf("|           |            | o elemento esta no inicio do vetor                  |\n");
    printf("| II        | VERDADEIRA | Busca sequencial nao requer dados ordenados         |\n");
    printf("| III       | VERDADEIRA | Busca binaria so funciona em dados ordenados        |\n");
    printf("\n");

    free(vetorGrande);
    return 0;
}