#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int eh_numero(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;  // n�o � n�mero
    }
    return 1;  // � n�mero
}

int main() {
    FILE *entrada = fopen("texto.txt", "r");
    FILE *saida = fopen("numeros.txt", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char palavra[100];

    while (fscanf(entrada, "%s", palavra) != EOF) {
        if (eh_numero(palavra)) {
            fprintf(saida, "%s\n", palavra);
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("N�meros extra�dos com sucesso para 'numeros.txt'.\n");
    return 0;
}
