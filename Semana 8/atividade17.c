#include <stdio.h>

int main() {
    int temp[] = {15, 17, 19, 21, 23, 25, 27, 30};
    int busca, ini = 0, fim = 7, meio, achou = 0;

    printf("temperatura para pesquisar: ");
    scanf("%d", &busca);

    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (temp[meio] == busca) {
            printf("temperatura registrada na posicao %d.\n", meio);
            achou = 1;
            break;
        }
        if (temp[meio] < busca){
            ini = meio + 1;
        }
        
        else {
            fim = meio - 1;
        }
    }

    if (!achou) {
        printf("nao registrada, insere na posicao %d.\n", ini);
    }
    return 0;
}