#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Lista de Alocação Dinâmica de Memória */

#define MAX_NOME 100

int main() {
    char **participantes = NULL;
    int n = 0;
    int capacidade = 10;
    char nome[MAX_NOME];

    participantes = (char **)malloc(capacidade * sizeof(char *));
    if (participantes == NULL) {
        fprintf(stderr, "Erro.\n");
        return 1;
    }

    while (1) {
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0; 

        if (strcmp(nome, "acabou") == 0) {
            break; 
        }

        if (n >= capacidade) {
            capacidade *= 2;
            participantes = (char **)realloc(participantes, capacidade * sizeof(char *));
            if (participantes == NULL) {
                fprintf(stderr, "Erro.\n");
                return 1;
            }
        }

        participantes[n] = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        if (participantes[n] == NULL) {
            fprintf(stderr, "Erro.\n");
            return 1;
        }
        strcpy(participantes[n], nome);
        n++;
    }

    unsigned int semente;
    scanf("%u", &semente);
    srand(semente); 

    int *sorteados = (int *)malloc(n * sizeof(int));
    if (sorteados == NULL) {
        fprintf(stderr, "Erro.\n");
        return 1;
    }
    memset(sorteados, 0, n * sizeof(int)); 

    int total_sorteados = 0;

    while (total_sorteados < n) {
        int indice_participante = rand() % n;

        if (sorteados[indice_participante] == 0) {
            printf("%s\n", participantes[indice_participante]);
            sorteados[indice_participante] = 1; 
            total_sorteados++;
        }
    }

    for (int i = 0; i < n; i++) {
        free(participantes[i]);
    }
    free(participantes);
    free(sorteados);

    return 0;
}
