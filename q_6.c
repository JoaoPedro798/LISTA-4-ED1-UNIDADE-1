#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA 100
#define MAX_LINHA 1000

int main() {
    char nome_arquivo[MAX_PALAVRA];
    char palavra_busca[MAX_PALAVRA];
    char linha[MAX_LINHA];
    int encontrou = 0;

    // Solicita nome do arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    // Solicita a palavra a ser buscada
    printf("Digite a palavra que deseja procurar: ");
    scanf("%s", palavra_busca);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nome_arquivo);
        return EXIT_FAILURE;
    }

    // Busca a palavra no arquivo
    while (fgets(linha, MAX_LINHA, arquivo) != NULL) {
        if (strstr(linha, palavra_busca) != NULL) {
            encontrou = 1;
            break;
        }
    }

    fclose(arquivo);

    // Exibe o resultado
    if (encontrou) {
        printf("A palavra '%s' foi encontrada no arquivo.\n", palavra_busca);
    } else {
        printf("A palavra '%s' não foi encontrada no arquivo.\n", palavra_busca);
    }

    return EXIT_SUCCESS;
}