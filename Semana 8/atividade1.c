#include <stdio.h>
#include <stdlib.h>

int main()
{
  int matriculas[] = {512, 102, 678, 205, 789, 317, 404};
  int busca;
  int tamanho = sizeof(matriculas) / sizeof(matriculas[0]);

  printf("Deseja buscar qual matricula? ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++)
  {
    if (matriculas[i] == busca)
    {
      printf("Aluno encontrado na posicao %d\n", i + 1);
      return 0;
    }
  }

  printf("Aluno não encontrado.\n");

  return 0;
}