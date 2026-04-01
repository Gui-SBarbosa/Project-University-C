#include <stdio.h>
#include <stdlib.h>

int main()
{
  int estoque[] = {55, 12, 89, 33, 21, 90, 44};
  int busca;
  int tamanho = sizeof(estoque) / sizeof(estoque[0]);

  printf("Deseja buscar qual produtos? ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++)
  {
    if (estoque[i] == busca)
    {
      printf("Produto encontrado na posicao %d\n", i + 1);
      return 0;
    }
  }

  printf("Produto não encontrado.\n");

  return 0;
}