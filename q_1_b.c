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
    int posicao;
/*-> esse vetor frase vai armazenar a linha lida do arquivo.
  -> esse ponteiro palavra vai somente apontar para cada palavra 
do arquivo, ele será usado pelo strtok() para apontar para essas palavras.
  -> essa variável posição vai servir para dizer qual palavra deseja ver.*/

    // Lê a linha inteira do arquivo
    fgets(frase, 100, arquivo);
/*-> esse "fgets" vai basicamente ler a linha do arquivo que 
vai estar armazenado dentro do vetor frase[100].
  -> essa "frase" é de onde a linha está armazenada.
  -> esse 100 é o quantidade de caracteres a ser lido.
  -> o arquivo é o ponteiro que aponta para o arquivo intro.txt*/
    
    // Remove o \n do final da frase
    frase[strcspn(frase, "\n")] = 0;
/*-> o strcspn(frase, "\n") vai basicamente porcurar na string frase o primeiro \n, 
depois ele vai retornar a posição do \n.
  -> a função frase[strcspn(frase, "\n")] = 0 vai basicamente acessar a
posição do \n que foi retornado e substituir o \n por \0, pois o \0
marca o fim da string.*/

    printf("Frase lida: %s\n", frase);
    printf("Digite a posição da palavra que deseja ver (começando de 1): ");
    scanf("%d", &posicao);

    // Pega a primeira palavra
    palavra = strtok(frase, " ");
/*-> o strtok é uma função da biblioteca string.h que vai basicamente dividir a string em pedaços menores,
ou seja, palavras. Ela vai retornar um ponteiro para o início de cada token.
  -> frase é a string que será dividida.
  -> " " vai definir onde que a string será quebrada.*/    
    
    // Percorre até a palavra desejada
    for(int i = 1; i < posicao && palavra != NULL; i++) {
        palavra = strtok(NULL, " ");
    }

    if(palavra != NULL) {
        printf("Palavra na posição %d: %s\n", posicao, palavra);
    } else {
        printf("Posição inválida!\n");
    }

    fclose(arquivo);
    return 0;
}