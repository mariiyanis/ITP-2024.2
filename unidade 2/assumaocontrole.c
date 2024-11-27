#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100
#define MAX_NOME 101

typedef struct {
    char nomes[MAX_PESSOAS][MAX_NOME];
    int total;
} Lista;

void inserir(Lista *lista, const char *nome) {
    if (lista->total < MAX_PESSOAS) {
        strcpy(lista->nomes[lista->total], nome);
        lista->total++;
    }
}

void remover(Lista *lista, const char *nome) {
    for (int i = 0; i < lista->total; i++) {
        if (strcmp(lista->nomes[i], nome) == 0) {

            for (int j = i; j < lista->total - 1; j++) {
                strcpy(lista->nomes[j], lista->nomes[j + 1]);
            }
            lista->total--;
            break;
        }
    }
}

void imprimir(const Lista *lista) {
    printf("Atualmente trabalhando:\n");
    for (int i = 0; i < lista->total; i++) {
        printf("%s \n", lista->nomes[i]);
    }
    printf("\n");
}

int main() {
    int n;
    char comando[10], nome[MAX_NOME];
    Lista lista;
    lista.total = 0;

    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {

        scanf("%s", comando);

        if (strcmp(comando, "INSERIR") == 0) {
            scanf("%s", nome);
            inserir(&lista, nome);
        } else if (strcmp(comando, "REMOVER") == 0) {
            scanf("%s", nome);
            remover(&lista, nome);
        } else if (strcmp(comando, "IMPRIMIR") == 0) {
            imprimir(&lista);
        }
    }

    return 0;
}
