#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor, int *iteracoes)
{
  int inicio = 0;
  int fim = tamanho - 1;

  *iteracoes = 0;

  while (inicio <= fim)
  {
    (*iteracoes)++;

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor)
    {
      return meio;
    }
    else if (vetor[meio] < valor)
    {
      inicio = meio + 1;
    }
    else
    {
      fim = meio - 1;
    }
  }

  return -1;
}

int main()
{
  int livros[] = {10, 23, 35, 47, 59, 62, 78, 91};
  int tamanho = sizeof(livros) / sizeof(livros[0]);

  int valor;
  int iteracoes;

  printf("Digite o ID do livro: ");
  scanf("%d", &valor);

  int posicao = buscaBinaria(livros, tamanho, valor, &iteracoes);

  if (posicao != -1)
  {
    printf("Livro encontrado na posicao %d\n", posicao);
  }
  else
  {
    printf("Livro nao encontrado\n");
  }

  printf("Numero de iteracoes: %d\n", iteracoes);

  return 0;
}