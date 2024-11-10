#include <stdio.h>

// Lista de Ponteiros

void calcular_media(int *A, int *B) {
    int menor, maior;
    
    if (*A < *B) {
        menor = *A;
        maior = *B;
    } else {
        menor = *B;
        maior = *A;
    }

    int media = (menor + maior) / 2;

    if (*A < *B) {
        *A = media;
        *B = (menor + maior) % 2; 
    } else {
        *B = media;
        *A = (menor + maior) % 2;
    }
}

int main() {
    int A, B;

    scanf("%d %d", &A, &B);

    calcular_media(&A, &B);


    printf("A = %d\n", A);
    printf("B = %d\n", B);

    return 0;
}
