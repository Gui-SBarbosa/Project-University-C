# Escolha de Algoritmos de Busca

## Cenário

- **Lista A:** [34, 7, 23, 89, 12, 55, 1, 67, 90, 18] (não ordenada)
- **Lista B:** lista com 1.000.000 elementos ordenados

---

## Lista A (Não Ordenada)

### Algoritmo escolhido: **Busca Sequencial**

### Justificativa

A lista A não está ordenada, o que impede o uso direto da busca binária.

### Complexidade

- Busca Sequencial: **O(n)**
- Busca Binária: **O(log n)** (exige ordenação)

### Custo de Ordenação

Para utilizar busca binária, seria necessário ordenar o vetor previamente, com custo médio de **O(n log n)**.

Como a lista possui apenas 10 elementos, o custo de ordenar não compensa.

### Eficiência Prática

Para listas pequenas e não ordenadas:

- A busca sequencial é mais simples
- Não exige pré-processamento
- Possui desempenho suficiente

### Conclusão

A melhor escolha para a Lista A é a **busca sequencial**.

---

## Lista B (Ordenada com 1.000.000 elementos)

### Algoritmo escolhido: **Busca Binária**

### Justificativa

A lista já está ordenada, permitindo o uso direto da busca binária.

### Complexidade

- Busca Sequencial: **O(n)**
- Busca Binária: **O(log n)**

Para 1.000.000 de elementos:

- Busca Sequencial: até **1.000.000 comparações**
- Busca Binária: aproximadamente **20 comparações** (log₂(1.000.000) ≈ 20)

### Custo de Ordenação

Não há custo adicional, pois a lista já está ordenada.

### Eficiência Prática

Para listas grandes:

- A busca sequencial se torna lenta
- A busca binária é altamente eficiente

### Conclusão

A melhor escolha para a Lista B é a **busca binária**.

---

## Conclusão Geral

A escolha do algoritmo depende de três fatores principais:

- Se a lista está ordenada
- O tamanho da lista
- O custo de ordenação

| Lista   | Situação               | Algoritmo Ideal  |
| ------- | ---------------------- | ---------------- |
| Lista A | Pequena e não ordenada | Busca Sequencial |
| Lista B | Grande e ordenada      | Busca Binária    |

A busca binária é mais eficiente em termos teóricos, porém sua aplicação depende da ordenação dos dados.
