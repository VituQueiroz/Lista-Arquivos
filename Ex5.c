#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_ALUNOS 100

typedef struct {
    char nome[MAX_NOME];
    float notas[4];
    float media;
} Aluno;

float calcular_media(float notas[], int qtd) {
    float soma = 0;
    for (int i = 0; i < qtd; i++) {
        soma += notas[i];
    }
    return soma / qtd;
}

int comparar(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    if (alunoB->media > alunoA->media) return 1;
    if (alunoB->media < alunoA->media) return -1;
    return 0;
}

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    Aluno alunos[MAX_ALUNOS];
    int qtd_alunos;
    char linha[256];

    arquivo_entrada = fopen("alunos.csv", "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir o arquivo alunos.csv");
        return 1;
    }

    if (fgets(linha, sizeof(linha), arquivo_entrada) != NULL) {
        sscanf(linha, "%d", &qtd_alunos);
    }

    for (int i = 0; i < qtd_alunos; i++) {
        if (fgets(linha, sizeof(linha), arquivo_entrada) != NULL) {

            char *token = strtok(linha, ",");
            strcpy(alunos[i].nome, token);

            for (int j = 0; j < 4; j++) {
                token = strtok(NULL, ",");
                alunos[i].notas[j] = atof(token);
            }

            alunos[i].media = calcular_media(alunos[i].notas, 4);
        }
    }

    fclose(arquivo_entrada);

    qsort(alunos, qtd_alunos, sizeof(Aluno), comparar);

    arquivo_saida = fopen("alunos_ordenados.csv", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao criar o arquivo alunos_ordenados.csv");
        return 1;
    }

    for (int i = 0; i < qtd_alunos; i++) {
        fprintf(arquivo_saida, "%s,%.2f,%.2f,%.2f,%.2f,%.2f\n",
                alunos[i].nome,
                alunos[i].notas[0], alunos[i].notas[1],
                alunos[i].notas[2], alunos[i].notas[3],
                alunos[i].media);
    }

    fclose(arquivo_saida);

    printf("Dados ordenados salvos em 'alunos_ordenados.csv'\n");
    return 0;
}
