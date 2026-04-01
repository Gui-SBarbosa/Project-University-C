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
  int ids[] = {101, 203, 305, 407, 509, 611, 713};
  int tamanho = sizeof(ids) / sizeof(ids[0]);

  int valor;

  printf("Digite o ID do usuario: ");
  scanf("%d", &valor);

  int posicao = buscaBinaria(ids, tamanho, valor);

  if (posicao != -1)
  {
    printf("Acesso permitido.");
  }
  else
  {
    printf("Acesso negado.");
  }

  return 0;
}