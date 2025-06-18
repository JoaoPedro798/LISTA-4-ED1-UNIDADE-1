#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 1000

// Verifica se a palavra é palíndromo
int eh_palindromo(const char palavra[]) {
    int i = 0;
    int j = strlen(palavra) - 1;

    while (i < j) {
        if (palavra[i] != palavra[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

// Converte para minúsculo e remove pontuações e espaços
void limpar_palavra(char palavra[]) {
    char limpa[TAM_MAX];
    int j = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        if (isalpha((unsigned char)palavra[i])) {
            limpa[j++] = tolower(palavra[i]);
        }
    }
    limpa[j] = '\0';
    strcpy(palavra, limpa);
}

int main() {
    FILE *arquivo;
    char palavra[TAM_MAX];
    int total_palindromos = 0;

    // Tente abrir o arquivo
    arquivo = fopen("palindromos.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Palíndromos encontrados:\n");

    // Lê palavra por palavra
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        limpar_palavra(palavra);
        if (strlen(palavra) > 0 && eh_palindromo(palavra)) {
            printf("%s\n", palavra);
            total_palindromos++;
        }
    }

    printf("Total de palíndromos encontrados: %d\n", total_palindromos);

    fclose(arquivo);
    return 0;
}
