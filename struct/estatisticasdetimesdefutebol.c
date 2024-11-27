#include <stdio.h>
#include <string.h>

/* Lista de Estruturas de Dados Heterogêneas */

#define MAX_TIMES 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int gols_marcados;
    int gols_sofridos;
} Time;

void ordenarTimes(Time times[], int n) {
    Time temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (times[i].gols_marcados < times[j].gols_marcados) {
                temp = times[i];
                times[i] = times[j];
                times[j] = temp;
            }
        }
    }
}

void lerTimes(Time times[], int n) {
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", times[i].nome);
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }
}

void exibirTimes(Time times[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", i + 1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
    }
}

int main() {
    int n;
    Time times[MAX_TIMES];

    scanf("%d", &n);

    lerTimes(times, n);

    ordenarTimes(times, n);

    exibirTimes(times, n);

    return 0;
}
