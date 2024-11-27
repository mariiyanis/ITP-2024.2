#include <stdio.h>
#include <string.h>

/* Lista de Estruturas de Dados Heterogêneas */

#define MAX_SMARTPHONES 100

typedef struct {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]) {
    if (qnt_cadastrada >= MAX_SMARTPHONES) {
        printf("Limite atingido.\n");
        return qnt_cadastrada; 
    }

    Smartphone novoSmartphone;
    scanf(" %[^\n]s", novoSmartphone.modelo);
    scanf("%d", &novoSmartphone.memoria);
    scanf("%f", &novoSmartphone.processador);
    scanf("%f", &novoSmartphone.camera);
    scanf("%f", &novoSmartphone.bateria);

    phones[qnt_cadastrada] = novoSmartphone;
    return qnt_cadastrada + 1;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin) {
    int encontrados = 0;
    for (int i = 0; i < qnt_cadastrada; i++) {
        if (phones[i].memoria >= reqMin.memoria &&
            phones[i].processador >= reqMin.processador &&
            phones[i].camera >= reqMin.camera &&
            phones[i].bateria >= reqMin.bateria) {
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\n", phones[i].memoria);
            printf("Processador: %.2fGhz\n", phones[i].processador);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n\n", phones[i].bateria);
            encontrados++;
        }
    }
    return encontrados;
}

int main() {
    Smartphone phones[MAX_SMARTPHONES];
    int qnt_cadastrada = 0;
    char resposta;
    
    do {
        scanf(" %c", &resposta);
        if (resposta == 's') {
            qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, phones);
        }
    } while (resposta == 's');

    Smartphone reqMin;
    scanf("%d", &reqMin.memoria);
    scanf("%f", &reqMin.processador);
    scanf("%f", &reqMin.camera);
    scanf("%f", &reqMin.bateria);

    int encontrados = pesquisaSmartphones(qnt_cadastrada, phones, reqMin);
    printf("%d smartphones encontrados.\n", encontrados);

    return 0;
}
