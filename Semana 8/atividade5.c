#include <stdio.h>

void mostrarVetor(int vetor[], int tamanho)
{
  printf("[");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d", vetor[i]);
    if (i < tamanho - 1)
    {
      printf(", ");
    }
  }
  printf("]\n");
}

void bubbleSort(int vetor[], int tamanho)
{
  for (int i = 0; i < tamanho - 1; i++)
  {
    for (int j = 0; j < tamanho - 1 - i; j++)
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
  int numeros[] = {45, 12, 78, 3, 56, 89, 23, 67};
  int tamanho = sizeof(numeros) / sizeof(numeros[0]);
  int valor;

  printf("Vetor antes da ordenacao: ");
  mostrarVetor(numeros, tamanho);

  bubbleSort(numeros, tamanho);

  printf("Vetor depois da ordenacao: ");
  mostrarVetor(numeros, tamanho);

  printf("Digite o valor que deseja buscar: ");
  scanf("%d", &valor);

  int posicao = buscaBinaria(numeros, tamanho, valor);

  if (posicao != -1)
  {
    printf("Valor encontrado na posicao %d do vetor ordenado.\n", posicao);
  }
  else
  {
    printf("Valor nao encontrado.\n");
  }

  return 0;
}