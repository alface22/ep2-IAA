#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 200
#define MAX_ATUALIZACOES 100

typedef struct {
    int valor;
    int posicao;
} lista;

void bubbleSort(lista v[], int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (v[j].valor > v[j + 1].valor) {
                lista aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int* melhorSolucao(lista* numero, int numeros, int horas, int* contador)
{
    int* numerosSolucao = (int*) malloc(sizeof(int) * numeros);
    for (int i = 0; i < numeros; i++) {
        if (horas - numero[i].valor >= 0) {
            horas -= numero[i].valor;
            numerosSolucao[(*contador)++] = numero[i].posicao;
        }
    }

    return numerosSolucao;
}

int main(int argc, char* argv[])
{
    int horas;
    sscanf(argv[1], "%i", &horas);

    int caso;
    sscanf(argv[2], "%i", &caso);

    char nome[MAX_FILENAME] = "";
    strcpy(nome, argv[3]);

    FILE* entrada = fopen(nome, "r");

    int numeroDeAtualizacoes;
    fscanf(entrada, "%i", &numeroDeAtualizacoes);

    lista numero[MAX_ATUALIZACOES];
    for (int i = 0; i < numeroDeAtualizacoes; i++) {
        numero[i].posicao = i + 1;
    }

    if (caso == 1) {

        for (int i = 0; i < numeroDeAtualizacoes; i++) {
            fscanf(entrada, "%i", &numero[i].valor);
        }

        fclose(entrada);

        bubbleSort(numero, numeroDeAtualizacoes);

        int contador = 0;
        int* solucao = melhorSolucao(numero, numeroDeAtualizacoes, horas, &contador);

        FILE* saida = fopen("saida.txt", "w");
        fprintf(saida, "%i ", contador);
        for (int i = 0; i < contador; i++) {
            fprintf(saida, "%i ", solucao[i]);
        }
        fclose(saida);
    } else if (caso == 2) {
    }

    return 0;
}
