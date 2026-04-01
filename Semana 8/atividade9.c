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
  int vetor[] = {5, 10, 15, 20, 25, 30};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);

  int valor;
  printf("Digite o valor que deseja buscar: ");
  scanf("%d", &valor);

  int resultado = buscaBinaria(vetor, tamanho, valor);

  if (resultado != -1)
  {
    printf("Elemento encontrado no indice %d\n", resultado);
  }
  else
  {
    printf("Elemento nao encontrado (retorno = -1)\n");
  }

  return 0;
}