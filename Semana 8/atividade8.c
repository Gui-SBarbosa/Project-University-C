#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor)
{
  int inicio = 0;
  int fim = tamanho - 1;

  while (inicio <= fim)
  {
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
  int notas[] = {2, 3, 5, 6, 7, 8, 9, 10};
  int tamanho = sizeof(notas) / sizeof(notas[0]);

  int valor;
  printf("Digite a nota que deseja buscar: ");
  scanf("%d", &valor);

  int posicao = buscaBinaria(notas, tamanho, valor);

  if (posicao != -1)
  {
    int maiores = tamanho - posicao - 1;

    printf("Nota encontrada na posicao %d\n", posicao);
    printf("Quantidade de alunos com nota maior: %d\n", maiores);
  }
  else
  {
    printf("Nota nao encontrada.\n");
  }

  return 0;
}