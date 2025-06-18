#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    float peso;
    float comprimento;
} Peixe;

int main() {
    FILE *arquivo = fopen("pescado.txt", "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo pescado.txt\n");
        return EXIT_FAILURE;
    }

    float peso_total = 0.0;
    Peixe peixe;

    while (fscanf(arquivo, "%s %f %f", peixe.nome, &peixe.peso, &peixe.comprimento) == 3) {
        peso_total += peixe.peso;
    }

    fclose(arquivo);

    // Converter de gramas para quilos
    float peso_total_kg = peso_total / 1000.0;
    
    printf("Peso total pescado: %.2f kg\n", peso_total_kg);

    return 0;
}