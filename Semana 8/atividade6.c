#include <stdio.h>
#include <string.h>

int main()
{
  char nomes[][20] = {"Daniel", "Ana", "Eduarda", "Carlos", "Bruna"};
  int tamanho = 5;

  char busca[20];
  int encontrado = 0;

  printf("Digite o nome que deseja buscar: ");
  scanf("%s", busca);

  for (int i = 0; i < tamanho; i++)
  {
    if (strcmp(nomes[i], busca) == 0)
    {
      printf("Nome encontrado: %s\n", nomes[i]);
      printf("Posicao no vetor: %d\n", i);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("Nome nao encontrado.\n");
  }

  return 0;
}