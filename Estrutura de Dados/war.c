// Game War

// Tarefa 
// Implementar o cadastro de Territorios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 30
#define MAX_TERRITORIOS 5

typedef struct {
    char nome[TAM_STRING];
    char dominioCor[TAM_STRING];
    int tropas;
} Territorio;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int cadastraTerritorio(Territorio *territorio) {
    printf("=====================\n");
    printf("Nome do Territorio: ");
    fgets(territorio->nome, TAM_STRING, stdin);
    territorio->nome[strcspn(territorio->nome, "\n")] = 0; // Remove newline

    printf("Cor de Dominio (ex: Azul, Verde): ");
    fgets(territorio->dominioCor, TAM_STRING, stdin);
    territorio->dominioCor[strcspn(territorio->dominioCor, "\n")] = 0; // Remove newline

    printf("Numero de Tropas: ");
    scanf("%d", &territorio->tropas);
    printf("=====================\n");
    printf("\n");
    limparBufferEntrada();

    return 0;
}

int main() {
    Territorio territorios[MAX_TERRITORIOS];

    printf("=====================\n");
    printf("Sistema de Territorios\n");
    printf("=====================\n");
    printf("Total de Territorios a serem cadastrados: %d\n", MAX_TERRITORIOS);
    printf("=====================\n");
    printf(" \n");
    // Código para adicionar territorios
    for(int i = 0; i < MAX_TERRITORIOS; i++){
        cadastraTerritorio(&territorios[i]);
        printf("%d\n",MAX_TERRITORIOS);
    }
    for(int i = 0; i < MAX_TERRITORIOS; i++){
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor de Dominio: %s\n", territorios[i].dominioCor);
        printf("Numero de Tropas: %d\n", territorios[i].tropas);
        printf("=====================\n");
    }

    return 0;
}