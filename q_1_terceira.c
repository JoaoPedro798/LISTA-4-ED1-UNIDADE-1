#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(){
    setlocale(LC_ALL,"portuguese");

    FILE *arquivo = fopen("intro.txt", "r");

    if (arquivo == NULL){
        printf("erro ao abrir arquivo\n");
        return 1;
    }

    char frase[100];
    char *palavra;
    int posicao = 5;  // Fixado para quinta palavra

    // Lê a linha inteira do arquivo
    fgets(frase, 100, arquivo);
    
    // Remove o \n do final da frase
    frase[strcspn(frase, "\n")] = 0;

    printf("Frase lida: %s\n", frase);

    // Pega a primeira palavra
    palavra = strtok(frase, " ");
    
    // Percorre até a quinta palavra
    for(int i = 1; i < posicao && palavra != NULL; i++) {
        palavra = strtok(NULL, " ");
    }

    if(palavra != NULL) {
        printf("A quinta palavra é: %s\n", palavra);
    } else {
        printf("A frase não tem cinco palavras!\n");
    }

    fclose(arquivo);
    return 0;
}