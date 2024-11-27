#include <stdio.h>
#include <string.h>

/* Lista de Estruturas de Dados Heterogêneas */

#define MAX_PESSOAS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char sexo;
} Pessoa;

void criar(Pessoa *p, const char *nome, int idade, char sexo) {
    strncpy(p->nome, nome, MAX_NOME - 1);
    p->nome[MAX_NOME - 1] = '\0';
    p->idade = idade;
    p->sexo = sexo;
}

void inserir(Pessoa pessoas[], int *contagem, Pessoa p) {
    if (*contagem < MAX_PESSOAS) {
        pessoas[*contagem] = p;
        (*contagem)++;
    } else {
        printf("Limite atingido.\n");
    }
}

void deletar(Pessoa pessoas[], int *contagem, Pessoa p) {
    int encontrado = 0;

    for (int i = 0; i < *contagem; i++) {
        if (strcmp(pessoas[i].nome, p.nome) == 0 && 
            pessoas[i].idade == p.idade && 
            pessoas[i].sexo == p.sexo) {
            encontrado = 1;
            for (int j = i; j < *contagem - 1; j++) {
                pessoas[j] = pessoas[j + 1];
            }
            (*contagem)--;
            break;
        }
    }

}

void imprimir(Pessoa pessoas[], int contagem) {
    for (int i = 0; i < contagem; i++) {
        printf("%s,%d,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
    }
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int contagem = 0;
    char comando;
    
    while (1) {
        scanf(" %c", &comando);
        
        if (comando == 'i') {
            char nome[MAX_NOME];
            int idade;
            char sexo;
            
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            
            Pessoa novaPessoa;
            criar(&novaPessoa, nome, idade, sexo);
            inserir(pessoas, &contagem, novaPessoa);
        } else if (comando == 'd') {
            char nome[MAX_NOME];
            int idade;
            char sexo;

            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            
            Pessoa pessoaDeletar;
            criar(&pessoaDeletar, nome, idade, sexo);
            deletar(pessoas, &contagem, pessoaDeletar);
        } else if (comando == 'p') {
            imprimir(pessoas, contagem);
            break; 
        } else {
            printf("Comando inválido.\n");
        }
    }

    return 0;
}
