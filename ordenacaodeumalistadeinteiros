#include <stdio.h>
#include <stdlib.h>

/* Lista de Alocação Dinâmica de Memória */

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int *arr = NULL;
    int n = 0;
    int capacity = 10;

    arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erro.\n");
        return 1;
    }

    while (1) {
        int num;
        if (scanf("%d", &num) != 1) {
            break;
        }

        if (n >= capacity) {
            capacity *= 2;
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                fprintf(stderr, "Erro.\n");
                return 1;
            }
        }

        arr[n++] = num;
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    free(arr);

    return 0;
}
