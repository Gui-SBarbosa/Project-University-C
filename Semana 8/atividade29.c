#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_INICIAL 10
#define FATOR_CARGA 0.75

typedef struct
{
    int *dados;
    int *ocupado;
    int tamanho;
    int quantidade;
} TabelaHash;

int funcaoHash(int chave, int tamanho)
{
    return chave % tamanho;
}

void inicializarTabela(TabelaHash *tabela, int tamanho)
{
    tabela->tamanho = tamanho;
    tabela->quantidade = 0;
    tabela->dados = (int *)malloc(tamanho * sizeof(int));
    tabela->ocupado = (int *)calloc(tamanho, sizeof(int));
}

void inserirHash(TabelaHash *tabela, int valor)
{
    int indice = funcaoHash(valor, tabela->tamanho);

    while (tabela->ocupado[indice] == 1)
    {
        indice = (indice + 1) % tabela->tamanho;
    }

    tabela->dados[indice] = valor;
    tabela->ocupado[indice] = 1;
    tabela->quantidade++;
}

int buscarHash(TabelaHash *tabela, int busca)
{
    int indice = funcaoHash(busca, tabela->tamanho);
    int comparacoes = 0;

    while (tabela->ocupado[indice] == 1)
    {
        comparacoes++;
        if (tabela->dados[indice] == busca)
        {
            printf("  Encontrado apos %d comparacoes\n", comparacoes);
            return indice;
        }
        indice = (indice + 1) % tabela->tamanho;
    }

    printf("  Nao encontrado apos %d comparacoes\n", comparacoes);
    return -1;
}

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

void ordenarVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int dados[] = {55, 23, 87, 12, 99, 34, 78, 45, 67, 88};
    int tamanho = 10;
    int busca = 45;
    int posicao;
    int comparacoes;

    printf("=== SISTEMA DE RECOMENDACAO - ANALISE DE BUSCA ===\n\n");
    printf("Dados: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", dados[i]);
    }
    printf("\n\n");

    printf("Cenario:\n");
    printf("  - Dados frequentemente atualizados\n");
    printf("  - Busca precisa ser extremamente rapida\n");
    printf("  - Ordenacao completa tem custo alto\n\n");

    printf("\tBUSCA SEQUENCIAL\n");
    posicao = buscaSequencial(dados, tamanho, busca, &comparacoes);
    printf("Comparacoes: %d\n", comparacoes);
    if (posicao != -1)
    {
        printf("Resultado: Valor %d encontrado no indice %d\n", busca, posicao);
    }
    else
    {
        printf("Resultado: Valor %d nao encontrado\n", busca);
    }
    printf("Complexidade: O(n) - tempo linear\n");
    printf("Problema: Lento para grandes volumes\n\n");

    printf("\tBUSCA BINARIA\n");
    int copia[10];
    for (int i = 0; i < tamanho; i++)
    {
        copia[i] = dados[i];
    }
    ordenarVetor(copia, tamanho);
    printf("Custo de ordenacao: O(n log n) - alto para cada atualizacao\n");
    posicao = buscaBinaria(copia, tamanho, busca, &comparacoes);
    printf("Comparacoes: %d\n", comparacoes);
    if (posicao != -1)
    {
        printf("Resultado: Valor %d encontrado no indice %d\n", busca, posicao);
    }
    else
    {
        printf("Resultado: Valor %d nao encontrado\n", busca);
    }
    printf("Problema: Ordenar apos cada atualizacao e muito custoso\n\n");

    printf("\tTABELA HASH (ESTRATEGIA RECOMENDADA)\n");
    TabelaHash tabela;
    inicializarTabela(&tabela, 20);

    for (int i = 0; i < tamanho; i++)
    {
        inserirHash(&tabela, dados[i]);
    }

    printf("Inserindo %d elementos na tabela hash\n", tamanho);
    printf("Busca em media: O(1) - tempo constante\n");
    printf("Nao requer ordenacao dos dados\n");
    printf("Atualizacoes sao rapidas O(1)\n\n");

    posicao = buscarHash(&tabela, busca);
    if (posicao != -1)
    {
        printf("Resultado: Valor %d encontrado\n", busca);
    }
    else
    {
        printf("Resultado: Valor %d nao encontrado\n", busca);
    }

    printf("\n\tDECISAO TECNICA\n");
    printf("ESTRATEGIA ADOTADA: TABELA HASH\n\n");
    printf("JUSTIFICATIVA:\n");
    printf("  1. Busca O(1) em media: Extremamente rapida para grandes volumes\n");
    printf("  2. Insercao O(1): Dados frequentemente atualizados sem custo alto\n");
    printf("  3. Nao requer ordenacao: Elimina o custo O(n log n) da ordenacao\n");
    printf("  4. Atualizacao eficiente: Adicionar/remover itens e muito rapido\n\n");

    printf("\tCOMPARATIVO:\n");
    printf("  Busca Sequencial: O(n)     - muito lento para grandes dados\n");
    printf("  Busca Binaria:    O(log n) - rapida mas ordenacao e cara\n");
    printf("  Tabela Hash:      O(1)     - ideal para o cenario proposto\n\n");

    free(tabela.dados);
    free(tabela.ocupado);

    return 0;
}