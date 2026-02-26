# 📊 Sorting Algorithms in C

Implementação dos principais algoritmos de ordenação em linguagem C, com medição de desempenho (tempo de execução, número de comparações e movimentações).

Projeto desenvolvido para avaliação acadêmica da disciplina de Estrutura de Dados.

---

## 🎯 Objetivo

Implementar e comparar os seguintes algoritmos de ordenação:

* Bubble Sort
* Selection Sort
* Insertion Sort
* Quick Sort
* Merge Sort
* Shell Sort

Cada algoritmo foi implementado como uma função separada, permitindo comparação justa de desempenho utilizando os mesmos conjuntos de dados.

---

## 🧠 Conceitos Aplicados

* Análise de complexidade de algoritmos
* Medição de desempenho com `clock()` (`<time.h>`)
* Contagem de comparações e movimentações
* Manipulação dinâmica de memória (`malloc`, `free`)
* Organização modular do código
* Estrutura de menu interativo

---

## 📂 Estrutura do Projeto

```
sorting_algorithms/
│
├── sorting_algorithms.c
├── relatorio.pdf
└── README.md
```

Todos os algoritmos estão implementados como funções separadas dentro do arquivo principal.

---

## ⚙️ Como Compilar e Executar

### 🔹 Windows (GCC / MinGW)

```bash
gcc sorting_algorithms.c -O2 -o sorting
sorting.exe
```

### 🔹 Linux / Mac

```bash
gcc sorting_algorithms.c -O2 -o sorting
./sorting
```

A flag `-O2` melhora a otimização e deixa a medição de tempo mais realista.

---

## 🖥️ Menu Interativo

Ao executar o programa, o usuário pode escolher:

```
1) Bubble Sort
2) Selection Sort
3) Insertion Sort
4) Quick Sort
5) Merge Sort
6) Shell Sort
7) Executar benchmark completo
0) Sair
```

Também é possível escolher:

* Tamanho do array
* Tipo do array:

  * Aleatório
  * Ordenado
  * Reverso
  * Quase Ordenado

---

## 📈 Métricas Avaliadas

Para cada algoritmo são medidos:

* ⏱ Tempo de execução (ms)
* 🔁 Número de comparações
* 🔄 Número de movimentações

Exemplo de medição de tempo:

```c
clock_t start = clock();
/* execução do algoritmo */
clock_t end = clock();

double tempo_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
```

---

## 🧪 Cenários de Teste

Os algoritmos foram testados com diferentes tamanhos:

* 100 elementos
* 1000 elementos
* 10000 elementos

E em diferentes estados:

* Array aleatório
* Array já ordenado
* Array em ordem reversa
* Array quase ordenado

---

## 📊 Complexidade Teórica

| Algoritmo      | Melhor Caso | Caso Médio  | Pior Caso  |
| -------------- | ----------- | ----------- | ---------- |
| Bubble Sort    | O(n)        | O(n²)       | O(n²)      |
| Selection Sort | O(n²)       | O(n²)       | O(n²)      |
| Insertion Sort | O(n)        | O(n²)       | O(n²)      |
| Quick Sort     | O(n log n)  | O(n log n)  | O(n²)      |
| Merge Sort     | O(n log n)  | O(n log n)  | O(n log n) |
| Shell Sort     | ~O(n log n) | ~O(n log n) | O(n²)      |

---

## 🏆 Resultados Esperados

* Bubble e Selection apresentam pior desempenho em arrays grandes.
* Insertion é eficiente para arrays quase ordenados.
* Quick e Merge apresentam melhor desempenho geral.
* Shell apresenta desempenho intermediário com boa eficiência prática.

---

## 📄 Relatório

O arquivo `relatorio.pdf` contém:

* Explicação da implementação
* Tabelas de resultados
* Comparação entre algoritmos
* Conclusão sobre desempenho
