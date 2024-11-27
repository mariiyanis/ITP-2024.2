#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100
#define MAX_NOME 100
#define MAX_TELEFONE 15

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
} Funcionario;

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &funcionarios[i].matricula);
        scanf(" %[^\n]s", funcionarios[i].nome);
        scanf(" %[^\n]s", funcionarios[i].telefone);
    }

    char consulta[150];
    int isFirstOutput = 1;

    while (1) {
        scanf(" %[^\n]s", consulta);

        if (strcmp(consulta, "FINAL") == 0) {
            break;
        }

        if (strncmp(consulta, "MAT", 3) == 0) {
            int matricula;
            sscanf(consulta + 4, "%d", &matricula);
            int encontrado = 0;

            for (i = 0; i < n; i++) {
                if (funcionarios[i].matricula == matricula) {
                    if (!isFirstOutput) printf("\n");
                    printf("%d\n%s\n%s\n", funcionarios[i].matricula, funcionarios[i].nome, funcionarios[i].telefone);
                    encontrado = 1;
                    isFirstOutput = 0;
                    break;
                }
            }
            if (!encontrado) {
                if (!isFirstOutput) printf("\n");
                printf("informacao nao encontrada\n");
                isFirstOutput = 0;
            }
        } else if (strncmp(consulta, "NOME", 4) == 0) {
            char nome[MAX_NOME];
            sscanf(consulta + 5, "%[^\n]", nome);
            int encontrado = 0;

            for (i = 0; i < n; i++) {
                if (strcmp(funcionarios[i].nome, nome) == 0) {
                    if (!isFirstOutput) printf("\n");
                    printf("%d\n%s\n%s\n", funcionarios[i].matricula, funcionarios[i].nome, funcionarios[i].telefone);
                    encontrado = 1;
                    isFirstOutput = 0;
                    break;
                }
            }
            if (!encontrado) {
                if (!isFirstOutput) printf("\n");
                printf("informacao nao encontrada\n");
                isFirstOutput = 0;
            }
        } else {
            printf("Inválido.\n");
        }
    }

    return 0;
}