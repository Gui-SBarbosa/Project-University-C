#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void imprimirVetor(int v[], int n, const char *label)
{
  if (label != NULL)
    printf("%s: ", label);
  printf("[");
  for (int i = 0; i < n; i++)
  {
    printf("%d", v[i]);
    if (i < n - 1)
      printf(", ");
  }
  printf("]\n");
}

void copiarVetor(int origem[], int destino[], int n)
{
  for (int i = 0; i < n; i++)
    destino[i] = origem[i];
}

void heapify(int v[], int n, int i)
{
  int maior = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;

  if (esq < n && v[esq] > v[maior])
    maior = esq;
  if (dir < n && v[dir] > v[maior])
    maior = dir;

  if (maior != i)
  {
    trocar(&v[i], &v[maior]);
    heapify(v, n, maior);
  }
}

void construirMaxHeap(int v[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(v, n, i);
}

void heapSort(int v[], int n)
{
  construirMaxHeap(v, n);
  for (int i = n - 1; i > 0; i--)
  {
    trocar(&v[0], &v[i]);
    heapify(v, i, 0);
  }
}

void shellSort(int v[], int n)
{
  int gap = 1;
  while (gap < n / 3)
    gap = gap * 3 + 1;

  while (gap >= 1)
  {
    for (int i = gap; i < n; i++)
    {
      int temp = v[i];
      int j = i;
      while (j >= gap && v[j - gap] > temp)
      {
        v[j] = v[j - gap];
        j -= gap;
      }
      v[j] = temp;
    }
    gap /= 3;
  }
}

void questao1()
{
  printf("============================================================\n");
  printf(" questao 1\n");
  printf("============================================================\n\n");
  printf("Por que HeapSort possui O(n log n) garantido e ShellSort nao?\n\n");

  printf("HeapSort:\n");
  printf("  O algoritmo tem duas fases: construcao do Max-Heap em O(n)\n");
  printf("  e extracao dos n-1 elementos, cada uma custando O(log n).\n");
  printf("  Como a altura da arvore e sempre floor(log2 n), o numero de\n");
  printf("  comparacoes e trocas nao depende da entrada - o comportamento\n");
  printf("  e identico para qualquer caso: O(n log n).\n\n");

  printf("ShellSort:\n");
  printf("  E uma extensao do Insertion Sort com gaps decrescentes ate 1.\n");
  printf(
      "  O problema e que a complexidade muda conforme a sequencia usada:\n");
  printf("    - Shell original (n/2, n/4, ...): O(n^2) no pior caso\n");
  printf("    - Knuth (1, 4, 13, 40, ...):      O(n^(3/2))\n");
  printf("    - Ciura / Sedgewick:              O(n^(4/3)) aprox.\n");
  printf(
      "  Para varias sequencias a complexidade exata ainda e desconhecida,\n");
  printf(
      "  o que torna o ShellSort imprevisivel em comparacao ao HeapSort.\n\n");
}

void questao2()
{
  printf("============================================================\n");
  printf(" questao 2\n");
  printf("============================================================\n\n");

  int v[] = {30, 12, 45, 6, 18, 3};
  int n = 6;

  imprimirVetor(v, n, "vetor original");

  printf("\na) construcao do Max-Heap:\n");
  printf("   indices: 0   1   2   3   4   5\n");
  printf("   valores: 30  12  45   6  18   3\n\n");
  printf("   pai de i = (i-1)/2  |  filhos de i = 2i+1 e 2i+2\n\n");

  printf(
      "   passo 1: heapify(i=2) => 45 ja e maior que filho 3 => sem troca\n");
  printf("            [30, 12, 45, 6, 18, 3]\n\n");

  printf("   passo 2: heapify(i=1) => filhos sao 6 e 18, maior = 18\n");
  printf("            troca 12 <-> 18\n");
  printf("            [30, 18, 45, 6, 12, 3]\n\n");

  printf("   passo 3: heapify(i=0) => filhos sao 18 e 45, maior = 45\n");
  printf("            troca 30 <-> 45, depois heapify em i=2: 3 < 30 => sem "
         "troca\n");
  printf("            [45, 18, 30, 6, 12, 3]\n\n");

  construirMaxHeap(v, n);
  imprimirVetor(v, n, "   Max-Heap final");
  printf("\n   arvore:\n");
  printf("            45\n");
  printf("           /  \\\n");
  printf("          18   30\n");
  printf("         / \\  /\n");
  printf("        6  12 3\n\n");

  printf("b) apos primeira extracao da raiz:\n");
  printf("   troca raiz (45) com ultimo (3), reduz heap e chama heapify\n\n");

  int extraido = v[0];
  trocar(&v[0], &v[n - 1]);
  printf("   elemento extraido: %d\n", extraido);
  heapify(v, n - 1, 0);
  imprimirVetor(v, n - 1, "   heap resultante");
  printf("\n   arvore:\n");
  printf("            30\n");
  printf("           /  \\\n");
  printf("          18   3\n");
  printf("         / \\\n");
  printf("        6  12\n\n");
}

void questao3()
{
  printf("============================================================\n");
  printf(" questao 3\n");
  printf("============================================================\n\n");

  printf("I   - ShellSort e estavel.\n");
  printf("      FALSO. O ShellSort faz trocas entre elementos distantes,\n");
  printf("      podendo alterar a ordem relativa de elementos iguais.\n\n");

  printf("II  - HeapSort usa estrutura de arvore binaria completa.\n");
  printf("      VERDADEIRO. O heap e armazenado em array onde o pai de i\n");
  printf("      esta em (i-1)/2 e os filhos em 2i+1 e 2i+2.\n\n");

  printf("III - HeapSort depende da sequencia de gaps.\n");
  printf("      FALSO. Isso se aplica ao ShellSort, nao ao HeapSort.\n\n");

  printf("IV  - ShellSort e uma melhoria do Insertion Sort.\n");
  printf("      VERDADEIRO. Donald Shell (1959) propus o uso de gaps\n");
  printf("      decrescentes para reduzir inversoes antes do passo final.\n\n");

  printf("  resposta: A) apenas II e IV\n\n");
}

void questao4()
{
  printf("============================================================\n");
  printf(" questao 4\n");
  printf("============================================================\n\n");

  printf("cenario: sistema que processa milhoes de registros por dia.\n\n");
  printf("algoritmo recomendado: HeapSort\n\n");

  printf("justificativa:\n");
  printf("  o HeapSort garante O(n log n) em qualquer situacao - entrada\n");
  printf("  aleatoria, ordenada ou invertida. para n = 10 milhoes isso\n");
  printf("  representa cerca de 2,3 * 10^8 operacoes de forma previsivel.\n\n");
  printf("  o ShellSort pode degradar dependendo da sequencia de gaps e do\n");
  printf("  perfil dos dados, o que e inaceitavel em producao com SLA.\n\n");
  printf("  ambos sao in-place (O(1) de memoria auxiliar), mas o HeapSort\n");
  printf("  mantem essa caracteristica independente da entrada.\n\n");
  printf("  obs: na pratica, algoritmos como Timsort e IntroSort combinam\n");
  printf("  HeapSort com outros para obter desempenho ainda melhor.\n\n");
}

void questao5()
{
  printf("============================================================\n");
  printf(" questao 5\n");
  printf("============================================================\n\n");

  printf("o Heap e usado em grafos principalmente como fila de prioridade,\n");
  printf("permitindo extrair o menor (ou maior) elemento em O(log n).\n\n");

  printf("exemplo: algoritmo de Dijkstra\n");
  printf("  encontra o menor caminho entre vertices em grafos ponderados.\n\n");
  printf("  funcionamento com Min-Heap:\n");
  printf("    1) insere o vertice inicial com distancia 0 no heap\n");
  printf("    2) extrai o vertice u de menor distancia acumulada\n");
  printf("    3) para cada vizinho v: se dist[u] + peso(u,v) < dist[v],\n");
  printf("       atualiza dist[v] e insere no heap\n");
  printf("    4) repete ate o heap esvaziar\n\n");
  printf("  com heap binario: O((V + E) log V)\n");
  printf("  sem heap (busca linear): O(V^2) - muito pior em grafos densos\n\n");
  printf("  outros exemplos: algoritmo de Prim (MST) e busca A*\n");
  printf("  seguem o mesmo principio de fila de prioridade com heap.\n\n");
}

void demonstracaoPratica()
{
  printf("============================================================\n");
  printf(" demonstracao pratica\n");
  printf("============================================================\n\n");

  int v1[] = {30, 12, 45, 6, 18, 3};
  int v2[] = {30, 12, 45, 6, 18, 3};
  int n = 6;

  imprimirVetor(v1, n, "vetor original");

  heapSort(v1, n);
  imprimirVetor(v1, n, "apos HeapSort ");

  shellSort(v2, n);
  imprimirVetor(v2, n, "apos ShellSort");

  printf("\n--- tempo com 500.000 elementos aleatorios ---\n");
  srand(42);
  int N = 500000;

  int *grande1 = (int *)malloc(N * sizeof(int));
  int *grande2 = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++)
    grande1[i] = grande2[i] = rand() % 1000000;

  clock_t t1 = clock();
  heapSort(grande1, N);
  clock_t t2 = clock();
  double msHeap = (double)(t2 - t1) / CLOCKS_PER_SEC * 1000.0;

  clock_t t3 = clock();
  shellSort(grande2, N);
  clock_t t4 = clock();
  double msShell = (double)(t4 - t3) / CLOCKS_PER_SEC * 1000.0;

  printf("HeapSort:  %.2f ms\n", msHeap);
  printf("ShellSort: %.2f ms\n", msShell);
  printf("\n(tempos variam por hardware e compilador)\n\n");

  free(grande1);
  free(grande2);
}

int main()
{
  printf("\n");
  printf("============================================================\n");
  printf("  analise comparativa: ShellSort vs HeapSort\n");
  printf("============================================================\n\n");

  questao1();
  questao2();
  questao3();
  questao4();
  questao5();
  demonstracaoPratica();

  return 0;
}