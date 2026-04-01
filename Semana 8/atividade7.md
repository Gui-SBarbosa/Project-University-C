# Comparação entre Busca Sequencial e Busca Binária

## Cenário

Considere um vetor com **1000 elementos ordenados**.

---

## Busca Sequencial

A busca sequencial percorre o vetor elemento por elemento até encontrar o valor desejado.

- **Melhor caso:** 1 operação (elemento está na primeira posição)
- **Pior caso:** 1000 operações (elemento está na última posição ou não está no vetor)
- **Caso médio:** aproximadamente **500 operações**

Isso ocorre porque, em média, o elemento procurado estará no meio do vetor.

- **Complexidade:** O(n)

---

## Busca Binária

A busca binária funciona dividindo o vetor ao meio a cada iteração.

Para um vetor com 1000 elementos:

- Número de operações ≈ log₂(1000)
- log₂(1000) ≈ **10 operações**

- **Melhor caso:** 1 operação
- **Pior caso:** aproximadamente 10 operações
- **Caso médio:** aproximadamente 10 operações

- **Complexidade:** O(log n)

---

## Comparação

| Algoritmo        | Caso Médio | Complexidade |
| ---------------- | ---------- | ------------ |
| Busca Sequencial | ~500       | O(n)         |
| Busca Binária    | ~10        | O(log n)     |

---

## Conclusão

A **busca binária é mais eficiente** nesse cenário, pois o vetor já está ordenado.

Enquanto a busca sequencial verifica os elementos um a um, a busca binária reduz o número de comparações drasticamente ao dividir o vetor pela metade a cada passo.

Em um vetor com 1000 elementos:

- Busca sequencial: cerca de **500 comparações**
- Busca binária: cerca de **10 comparações**

Portanto, para grandes volumes de dados ordenados, a busca binária é a melhor escolha.
