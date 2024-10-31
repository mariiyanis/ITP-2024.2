/* Soma das diagonais de uma raiz */

#include <stdio.h>

int main() {
    int tamMatriz, soma = 0;

    scanf("%d", &tamMatriz);

    int matriz[tamMatriz][tamMatriz];

    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < tamMatriz; i++) {
        soma += matriz[i][i];                      
        soma += matriz[i][tamMatriz - i - 1];   
    }


    if (tamMatriz % 2 == 1) {
        int meio = tamMatriz / 2;
    }

    printf("%d\n", soma);

    return 0;
}