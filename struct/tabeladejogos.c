/* O Código não tá pronto */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMES 100
#define MAX_NOME 200

typedef struct {
    char nome[MAX_NOME];
    int vitorias;
    int empates;
    int derrotas;
    int gols_feitos;
    int gols_sofridos;
    int pontos;
    int partidas;
    int saldo_gols;
} Time;

void ler_times(Time times[], int t) {
    for (int i = 0; i < t; i++) {
        char buffer[500];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%[^;]; %d %d %d %d %d", 
               times[i].nome, 
               &times[i].vitorias, 
               &times[i].empates, 
               &times[i].derrotas, 
               &times[i].gols_feitos, 
               &times[i].gols_sofridos);
        
        times[i].pontos = (times[i].vitorias * 3) + times[i].empates;
        times[i].partidas = times[i].vitorias + times[i].empates + times[i].derrotas;
        times[i].saldo_gols = times[i].gols_feitos - times[i].gols_sofridos;
    }
}

int comparar(const void *a, const void *b) {
    Time *timeA = (Time *)a;
    Time *timeB = (Time *)b;

    if (timeA->pontos != timeB->pontos) {
        return timeB->pontos - timeA->pontos;
    }
    if (timeA->vitorias != timeB->vitorias) {
        return timeB->vitorias - timeA->vitorias;
    }
    return timeB->saldo_gols - timeA->saldo_gols;
}

void imprimir_tabela(Time times[], int t) {
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    for (int i = 0; i < t; i++) {
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n",
               times[i].nome,
               times[i].pontos,
               times[i].partidas,
               times[i].vitorias,
               times[i].empates,
               times[i].derrotas,
               times[i].gols_feitos,
               times[i].gols_sofridos,
               times[i].saldo_gols);
    }

    printf("\nTimes na zona da libertadores:\n");
    for (int i = 0; i < (t < 6 ? t : 6); i++) {
        printf("%s\n", times[i].nome);
    }
/* Tem algum erro aqui pois em um dos testes dois times estão trocados de lugar, mas ainda não identifiquei */
    printf("\nTimes rebaixados:\n");
    int rebaixados_count = 4; 
    for (int i = t - rebaixados_count; i < t; i++) {
        printf("%s\n", times[i].nome);
    }
}

int main() {
    int t;
    Time times[MAX_TIMES];

    scanf("%d\n", &t);

    ler_times(times, t);
    
    qsort(times, t, sizeof(Time), comparar);

    imprimir_tabela(times, t);

    return 0;
}
