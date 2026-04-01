#include <stdio.h>

void selectionSort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min])
                min = j;
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

int main()
{
    int dados[] = {88, 23, 45, 12, 67, 34, 90, 10};
    int n = 8, busca;

    selectionSort(dados, n);
    printf("dados ordenados: ");
    for (int i = 0; i < n; i++)
        printf("%d ", dados[i]);

    //    Antes da ordenação, o custo de busca é O(n).
    //    Após ordenar, o custo de busca cai para O(log n).
    //    No entanto, a ordenação em si custa O(n²), então ela só vale a pena
    //    se formos realizar MUITAS buscas no mesmo conjunto de dados.

    return 0;
}