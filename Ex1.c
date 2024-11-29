#include <stdio.h>

void main() {
    FILE *file;
    char texto[256];

    file = fopen("mensagem.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(texto, 256, file) != NULL) { 
        printf("%s", texto);
    }

    fclose(file);
}