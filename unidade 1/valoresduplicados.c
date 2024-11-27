/* Valores Duplicados */

#include <stdio.h>
#include <stdbool.h>

int main() {
    int tam, i, j;
    
    scanf("%d", &tam);
    
    int vetor[tam];
    bool visto[tam];
    
    for (i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
        visto[i] = false;
    }
    
    for (i = 0; i < tam; i++) {
        if (!visto[i]) {
            for (j = i + 1; j < tam; j++) {
                if (vetor[i] == vetor[j]) {
                    printf("%d ", vetor[i]);
                    visto[j] = true;
                    break;
                }
            }
        }
    }
    
    printf("\n");
    
    return 0;
}
