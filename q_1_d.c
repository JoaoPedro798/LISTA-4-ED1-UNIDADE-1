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

    char linha[100];
    int linha_atual = 0;
    int linha_desejada = 2;  // Fixado para segunda linha

    // Lê até encontrar a linha desejada ou fim do arquivo
    while(fgets(linha, 100, arquivo) != NULL) {
        linha_atual++;
        if(linha_atual == linha_desejada) {
            // Remove o \n do final da linha
            linha[strcspn(linha, "\n")] = 0;
            printf("Linha %d: %s\n", linha_atual, linha);
            break;
        }
    }

    if(linha_atual < linha_desejada) {
        printf("O arquivo não tem %d linhas!\n", linha_desejada);
    }

    fclose(arquivo);
    return 0;
}