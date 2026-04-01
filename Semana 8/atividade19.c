#include <stdio.h>

int main() {
    int v[] = {12, 45, 12, 67, 89, 45, 23};
    int n = 7;

    printf("valores duplicados: ");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] == v[j]) {
                printf("%d ", v[i]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}