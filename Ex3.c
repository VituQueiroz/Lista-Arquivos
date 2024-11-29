#include <stdio.h>

int main() {
    FILE *arquivo;
    char titulo[100];
    int ano;

    arquivo = fopen("blog.txt", "a");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        printf("Digite o título do post %d: ", i + 1);
        fgets(titulo, sizeof(titulo), stdin);

        titulo[strcspn(titulo, "\n")] = '\0';

        printf("Digite o ano de publicação do post %d: ", i + 1);
        scanf("%d", &ano);
        getchar();

        fprintf(arquivo, "Título: %s\nAno: %d\n\n", titulo, ano);
    }

    fclose(arquivo);

    printf("\nNovos posts adicionados ao arquivo 'blog.txt' com sucesso!\n");

    return 0;
}
