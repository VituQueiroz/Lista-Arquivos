#include <stdio.h>
#include <string.h>

#define MAX_TITULO 100
#define MAX_POSTS 5

typedef struct {
    char titulo[MAX_TITULO];
    int ano;
} Post;

int main() {
    FILE *arquivo;
    Post posts[MAX_POSTS];
    int menor_ano, maior_ano;
    char titulo_menor[MAX_TITULO], titulo_maior[MAX_TITULO];

    arquivo = fopen("blog.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo blog.txt");
        return 1;
    }

    for (int i = 0; i < MAX_POSTS; i++) {
        fscanf(arquivo, " %[^\n]", posts[i].titulo);
        // Lê o ano
        fscanf(arquivo, "%d", &posts[i].ano);
    }

    fclose(arquivo);

    menor_ano = posts[0].ano;
    maior_ano = posts[0].ano;
    strcpy(titulo_menor, posts[0].titulo);
    strcpy(titulo_maior, posts[0].titulo);

    printf("Dados dos posts:\n");
    for (int i = 0; i < MAX_POSTS; i++) {
        printf("Título: %s\nPostado em: %d\n\n", posts[i].titulo, posts[i].ano);

        if (posts[i].ano < menor_ano) {
            menor_ano = posts[i].ano;
            strcpy(titulo_menor, posts[i].titulo);
        }

        if (posts[i].ano > maior_ano) {
            maior_ano = posts[i].ano;
            strcpy(titulo_maior, posts[i].titulo);
        }
    }

    printf("Post com o menor ano de publicação:\n");
    printf("Título: %s\nAno: %d\n\n", titulo_menor, menor_ano);

    printf("Post com o maior ano de publicação:\n");
    printf("Título: %s\nAno: %d\n", titulo_maior, maior_ano);

    return 0;
}
