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
/*nessa linha 15 essa variável será usada para armazenar o 8º caractere que
será lido no arquivo.*/    

    for(int i = 0; i < 8; i++){
        fscanf(arquivo, "%c", &c);
    }
/*nessa linha 18, o programa vai basicamente ler o conteúdo 
do arquivo e mostrar na tela o 8º caractere. Esse "%c" vai
pegar o caractere que estiver no endereço que quer encontrar.*/
    fclose(arquivo);

    printf("%c", c);

    return 0;
}