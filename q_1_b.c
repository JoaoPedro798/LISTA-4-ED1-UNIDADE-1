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
do arquivo, ele ser� usado pelo strtok() para apontar para essas palavras.
  -> essa vari�vel posi��o vai servir para dizer qual palavra deseja ver.*/

    // L� a linha inteira do arquivo
    fgets(frase, 100, arquivo);
/*-> esse "fgets" vai basicamente ler a linha do arquivo que 
vai estar armazenado dentro do vetor frase[100].
  -> essa "frase" � de onde a linha est� armazenada.
  -> esse 100 � o quantidade de caracteres a ser lido.
  -> o arquivo � o ponteiro que aponta para o arquivo intro.txt*/
    
    // Remove o \n do final da frase
    frase[strcspn(frase, "\n")] = 0;
/*-> o strcspn(frase, "\n") vai basicamente porcurar na string frase o primeiro \n, 
depois ele vai retornar a posi��o do \n.
  -> a fun��o frase[strcspn(frase, "\n")] = 0 vai basicamente acessar a
posi��o do \n que foi retornado e substituir o \n por \0, pois o \0
marca o fim da string.*/

    printf("Frase lida: %s\n", frase);
    printf("Digite a posi��o da palavra que deseja ver (come�ando de 1): ");
    scanf("%d", &posicao);

    // Pega a primeira palavra
    palavra = strtok(frase, " ");
/*-> o strtok � uma fun��o da biblioteca string.h que vai basicamente dividir a string em peda�os menores,
ou seja, palavras. Ela vai retornar um ponteiro para o in�cio de cada token.
  -> frase � a string que ser� dividida.
  -> " " vai definir onde que a string ser� quebrada.*/    
    
    // Percorre at� a palavra desejada
    for(int i = 1; i < posicao && palavra != NULL; i++) {
        palavra = strtok(NULL, " ");
    }

    if(palavra != NULL) {
        printf("Palavra na posi��o %d: %s\n", posicao, palavra);
    } else {
        printf("Posi��o inv�lida!\n");
    }

    fclose(arquivo);
    return 0;
}