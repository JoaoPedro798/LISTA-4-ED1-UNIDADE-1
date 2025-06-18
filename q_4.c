#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

const char* verificar_situacao(float n1, float n2, float n3) {
    float media = (n1 + n2 + n3) / 3.0;
    
    if (media >= 7.0)
        return "Aprovado";
    else if (media >= 4.0)
        return "Quarta Prova";
    else
        return "Reprovado";
}

int main() {
    FILE *entrada = fopen("notas.txt", "r");
    if (entrada == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo de notas\n");
        return EXIT_FAILURE;
    }

    FILE *saida = fopen("situacao.txt", "w");
    if (saida == NULL) {
        fprintf(stderr, "Erro ao criar arquivo de situação\n");
        fclose(entrada);
        return EXIT_FAILURE;
    }

    Aluno aluno;
    while (fscanf(entrada, "%s %f %f %f", 
           aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3) == 4) {
        
        const char* situacao = verificar_situacao(aluno.nota1, aluno.nota2, aluno.nota3);
        fprintf(saida, "%s %s\n", aluno.nome, situacao);
    }

    fclose(entrada);
    fclose(saida);
    
    printf("Arquivo de situações gerado com sucesso!\n");
    return 0;