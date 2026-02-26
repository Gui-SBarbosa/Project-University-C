#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
  long long comparisons;
  long long moves; // movimentações (trocas/atribuições)
} Metrics;

void resetMetrics(Metrics *m)
{
  m->comparisons = 0;
  m->moves = 0;
}

void printArray(const int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void copyArray(const int *src, int *dst, int n)
{
  memcpy(dst, src, n * sizeof(int));
}

static inline void swap(int *a, int *b, Metrics *m)
{
  int tmp = *a;
  m->moves++;
  *a = *b;
  m->moves++;
  *b = tmp;
  m->moves++;
}

/* -----------------------------
   GERADORES DE DADOS (TESTES)
------------------------------*/
void fillRandom(int *arr, int n, int maxValue)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % maxValue;
  }
}

void fillSorted(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = i;
}

void fillReverse(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = n - 1 - i;
}

void fillNearlySorted(int *arr, int n)
{
  // começa ordenado e faz algumas trocas aleatórias
  fillSorted(arr, n);
  int swaps = (n / 20) + 1; // ~5% de bagunça
  for (int i = 0; i < swaps; i++)
  {
    int a = rand() % n;
    int b = rand() % n;
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
  }
}

/* -----------------------------
   ALGORITMOS DE ORDENAÇÃO
------------------------------*/

// 1) Bubble Sort
void bubbleSort(int *arr, int n, Metrics *m)
{
  for (int i = 0; i < n - 1; i++)
  {
    int swapped = 0;
    for (int j = 0; j < n - 1 - i; j++)
    {
      m->comparisons++;
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1], m);
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
}

// 2) Selection Sort
void selectionSort(int *arr, int n, Metrics *m)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
    {
      m->comparisons++;
      if (arr[j] < arr[minIdx])
        minIdx = j;
    }
    if (minIdx != i)
      swap(&arr[i], &arr[minIdx], m);
  }
}

// 3) Insertion Sort
void insertionSort(int *arr, int n, Metrics *m)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    m->moves++;
    int j = i - 1;

    while (j >= 0)
    {
      m->comparisons++;
      if (arr[j] > key)
      {
        arr[j + 1] = arr[j];
        m->moves++;
        j--;
      }
      else
      {
        break;
      }
    }
    arr[j + 1] = key;
    m->moves++;
  }
}

// 4) Quick Sort (Lomuto)
int partitionLomuto(int *arr, int low, int high, Metrics *m)
{
  int pivot = arr[high];
  m->moves++;
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    m->comparisons++;
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j], m);
    }
  }
  swap(&arr[i + 1], &arr[high], m);
  return i + 1;
}

void quickSortRec(int *arr, int low, int high, Metrics *m)
{
  if (low < high)
  {
    int p = partitionLomuto(arr, low, high, m);
    quickSortRec(arr, low, p - 1, m);
    quickSortRec(arr, p + 1, high, m);
  }
}

void quickSort(int *arr, int n, Metrics *m)
{
  quickSortRec(arr, 0, n - 1, m);
}

// 5) Merge Sort
void merge(int *arr, int l, int mid, int r, Metrics *m)
{
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));
  if (!L || !R)
  {
    printf("Erro de memória no merge.\n");
    exit(1);
  }

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[l + i];
    m->moves++;
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[mid + 1 + j];
    m->moves++;
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    m->comparisons++;
    if (L[i] <= R[j])
    {
      arr[k++] = L[i++];
      m->moves++;
    }
    else
    {
      arr[k++] = R[j++];
      m->moves++;
    }
  }

  while (i < n1)
  {
    arr[k++] = L[i++];
    m->moves++;
  }
  while (j < n2)
  {
    arr[k++] = R[j++];
    m->moves++;
  }

  free(L);
  free(R);
}

void mergeSortRec(int *arr, int l, int r, Metrics *m)
{
  if (l < r)
  {
    int mid = l + (r - l) / 2;
    mergeSortRec(arr, l, mid, m);
    mergeSortRec(arr, mid + 1, r, m);
    merge(arr, l, mid, r, m);
  }
}

void mergeSort(int *arr, int n, Metrics *m)
{
  mergeSortRec(arr, 0, n - 1, m);
}

// 6) Shell Sort (gap = n/2)
void shellSort(int *arr, int n, Metrics *m)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      int temp = arr[i];
      m->moves++;
      int j = i;

      while (j >= gap)
      {
        m->comparisons++;
        if (arr[j - gap] > temp)
        {
          arr[j] = arr[j - gap];
          m->moves++;
          j -= gap;
        }
        else
        {
          break;
        }
      }
      arr[j] = temp;
      m->moves++;
    }
  }
}

/* -----------------------------
   EXECUÇÃO PADRÃO (BENCHMARK)
------------------------------*/

typedef void (*SortFn)(int *, int, Metrics *);

typedef struct
{
  const char *name;
  SortFn fn;
} Algo;

double runAlgorithm(const Algo *algo, const int *base, int n, Metrics *m, int printIfSmall)
{
  int *work = (int *)malloc(n * sizeof(int));
  if (!work)
  {
    printf("Erro de memória.\n");
    exit(1);
  }

  copyArray(base, work, n);
  resetMetrics(m);

  if (printIfSmall)
  {
    printf("Antes: ");
    printArray(work, n);
  }

  clock_t start = clock();
  algo->fn(work, n, m);
  clock_t end = clock();

  if (printIfSmall)
  {
    printf("Depois: ");
    printArray(work, n);
  }

  free(work);

  double ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
  return ms;
}

void benchmarkDataset(const char *datasetName, void (*fillFn)(int *, int), int n)
{
  Algo algos[] = {
      {"Bubble Sort", bubbleSort},
      {"Selection Sort", selectionSort},
      {"Insertion Sort", insertionSort},
      {"Quick Sort", quickSort},
      {"Merge Sort", mergeSort},
      {"Shell Sort", shellSort},
  };

  int algoCount = (int)(sizeof(algos) / sizeof(algos[0]));

  int *base = (int *)malloc(n * sizeof(int));
  if (!base)
  {
    printf("Erro de memória.\n");
    exit(1);
  }

  // Se o fill for random, ele precisa de maxValue. Aqui tratamos separadamente.
  // Para simplificar, se datasetName for "Aleatório", geramos random aqui.
  if (strcmp(datasetName, "Aleatório") == 0)
  {
    fillRandom(base, n, n * 10);
  }
  else
  {
    fillFn(base, n);
  }

  int printIfSmall = (n <= 30);

  printf("\n==============================\n");
  printf("Dataset: %s | Tamanho: %d\n", datasetName, n);
  printf("==============================\n");

  printf("%-14s | %-10s | %-14s | %-14s\n", "Algoritmo", "Tempo(ms)", "Comparações", "Movimentações");
  printf("--------------------------------------------------------------------------\n");

  for (int i = 0; i < algoCount; i++)
  {
    Metrics m;
    double ms = runAlgorithm(&algos[i], base, n, &m, printIfSmall);
    printf("%-14s | %-10.3f | %-14lld | %-14lld\n", algos[i].name, ms, m.comparisons, m.moves);
  }

  free(base);
}

void runAllTests()
{
  // Ajuste de tamanhos aqui (use os que o professor pediu)
  int sizes[] = {100, 1000, 10000};
  int sizeCount = (int)(sizeof(sizes) / sizeof(sizes[0]));

  for (int i = 0; i < sizeCount; i++)
  {
    int n = sizes[i];

    benchmarkDataset("Aleatório", NULL, n);
    benchmarkDataset("Ordenado", fillSorted, n);
    benchmarkDataset("Reverso", fillReverse, n);
    benchmarkDataset("Quase Ordenado", fillNearlySorted, n);
  }
}

void runMenuSingleAlgorithm(int choice)
{
  Algo algos[] = {
      {"Bubble Sort", bubbleSort},
      {"Selection Sort", selectionSort},
      {"Insertion Sort", insertionSort},
      {"Quick Sort", quickSort},
      {"Merge Sort", mergeSort},
      {"Shell Sort", shellSort},
  };

  int algoCount = (int)(sizeof(algos) / sizeof(algos[0]));
  if (choice < 1 || choice > algoCount)
  {
    printf("Opção inválida.\n");
    return;
  }

  int n;
  printf("Digite o tamanho do array (ex: 10, 100, 1000): ");
  scanf("%d", &n);
  if (n <= 0)
  {
    printf("Tamanho inválido.\n");
    return;
  }

  int type;
  printf("Escolha o tipo de array:\n");
  printf("1) Aleatório\n2) Ordenado\n3) Reverso\n4) Quase Ordenado\n> ");
  scanf("%d", &type);

  int *base = (int *)malloc(n * sizeof(int));
  if (!base)
  {
    printf("Erro de memória.\n");
    exit(1);
  }

  switch (type)
  {
  case 1:
    fillRandom(base, n, n * 10);
    break;
  case 2:
    fillSorted(base, n);
    break;
  case 3:
    fillReverse(base, n);
    break;
  case 4:
    fillNearlySorted(base, n);
    break;
  default:
    printf("Tipo inválido.\n");
    free(base);
    return;
  }

  Metrics m;
  int printIfSmall = (n <= 30);

  printf("\nExecutando: %s\n", algos[choice - 1].name);
  double ms = runAlgorithm(&algos[choice - 1], base, n, &m, printIfSmall);

  printf("\nResultado:\n");
  printf("Tempo: %.3f ms\n", ms);
  printf("Comparações: %lld\n", m.comparisons);
  printf("Movimentações: %lld\n", m.moves);

  free(base);
}

int main()
{
  srand((unsigned)time(NULL));

  int opt;
  do
  {
    printf("\n=========== MENU ===========\n");
    printf("1) Executar Bubble Sort\n");
    printf("2) Executar Selection Sort\n");
    printf("3) Executar Insertion Sort\n");
    printf("4) Executar Quick Sort\n");
    printf("5) Executar Merge Sort\n");
    printf("6) Executar Shell Sort\n");
    printf("7) Rodar TODOS os testes (benchmark completo)\n");
    printf("0) Sair\n");
    printf("> ");
    scanf("%d", &opt);

    if (opt >= 1 && opt <= 6)
    {
      runMenuSingleAlgorithm(opt);
    }
    else if (opt == 7)
    {
      runAllTests();
    }
    else if (opt == 0)
    {
      printf("Saindo...\n");
    }
    else
    {
      printf("Opção inválida.\n");
    }
  } while (opt != 0);

  return 0;
}