/* NFT */

#include <stdio.h>

int main() {
    int L, C;

    scanf("%d", &L);

    for (int i = 0; i < L; i++) {
        scanf("%d", &C);

        for (int j = 0; j < C; j++) {
            printf("*");
        }
        printf("\n"); 
    }

    return 0;
}