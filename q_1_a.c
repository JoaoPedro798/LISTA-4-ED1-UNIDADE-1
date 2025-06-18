#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL,"portuguese");

    FILE *arquivo = fopen("intro.txt", "r");

    if (arquivo == NULL){
        printf("erro ao abrir arquivo\n");
        return 1;
    }

    char c;
/*nessa linha 15 essa vari�vel ser� usada para armazenar o 8� caractere que
ser� lido no arquivo.*/    

    for(int i = 0; i < 8; i++){
        fscanf(arquivo, "%c", &c);
    }
/*nessa linha 18, o programa vai basicamente ler o conte�do 
do arquivo e mostrar na tela o 8� caractere. Esse "%c" vai
pegar o caractere que estiver no endere�o que quer encontrar.*/
    fclose(arquivo);

    printf("%c", c);

    return 0;
}