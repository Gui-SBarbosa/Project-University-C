# Busca Sequencial em Vetor Não Ordenado (500 elementos)

## Descrição

A busca sequencial percorre o vetor do início ao fim, comparando cada elemento com o valor procurado até encontrá-lo ou até chegar ao final.

Em um vetor com 500 elementos:

- No melhor caso, o valor está na primeira posição, sendo necessário apenas 1 comparação.
- No pior caso, o valor está na última posição ou não está presente, sendo necessárias até 500 comparações.

---

## Código em C

```c
#include <stdio.h>

int buscaSequencial(int vetor[], int tamanho, int valor, int *operacoes) {
    *operacoes = 0;

    for (int i = 0; i < tamanho; i++) {
        (*operacoes)++;
        if (vetor[i] == valor) {
            return i;
        }
    }

    return -1;
}

int main() {
    int vetor[500];
    int operacoes;
    int resultado;

    for (int i = 0; i < 500; i++) {
        vetor[i] = i + 1;
    }

    resultado = buscaSequencial(vetor, 500, 1, &operacoes);
    printf("Melhor caso: indice %d, operacoes %d\n", resultado, operacoes);

    resultado = buscaSequencial(vetor, 500, 500, &operacoes);
    printf("Pior caso: indice %d, operacoes %d\n", resultado, operacoes);

    return 0;
}
```
