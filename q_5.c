#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_vogal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int is_consoante(char c) {
    c = tolower(c);
    return (isalpha(c) && !is_vogal(c));
}

int main() {
    FILE *arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return EXIT_FAILURE;
    }

    int total = 0;
    int vogais = 0;
    int consoantes = 0;
    int outros = 0;
    char c;

    while ((c = fgetc(arquivo)) != EOF) {
        total++;
        
        if (is_vogal(c))
            vogais++;
        else if (is_consoante(c))
            consoantes++;
        else
            outros++;
    }

    fclose(arquivo);

    printf("Estat�sticas do arquivo:\n");
    printf("Total de caracteres: %d\n", total);
    printf("N�mero de vogais: %d\n", vogais);
    printf("N�mero de consoantes: %d\n", consoantes);
    printf("Outros caracteres: %d\n", outros);

    return 0;
}