#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100

// ========================
// Estruturas de dados
// ========================

// Estrutura de um Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Nó da lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// ========================
// Variáveis globais
// ========================

Item mochilaVetor[MAX_ITENS];
int qtdItensVetor = 0;

No* mochilaLista = NULL;

int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// ========================
// Funções auxiliares
// ========================

void exibirItem(Item item) {
    printf("Nome: %s | Tipo: %s | Quantidade: %d\n", item.nome, item.tipo, item.quantidade);
}

// ========================
// Funções para Vetor
// ========================

// Inserir no vetor
void inserirItemVetor(Item novo) {
    if (qtdItensVetor < MAX_ITENS) {
        mochilaVetor[qtdItensVetor++] = novo;
        printf("Item inserido no vetor com sucesso!\n");
    } else {
        printf("Mochila (vetor) cheia!\n");
    }
}

// Remover item do vetor por nome
void removerItemVetor(char* nome) {
    int i, j;
    for (i = 0; i < qtdItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (j = i; j < qtdItensVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            qtdItensVetor--;
            printf("Item removido do vetor!\n");
            return;
        }
    }
    printf("Item nao encontrado no vetor.\n");
}

// Listar vetor
void listarVetor() {
    printf("\n--- Itens no vetor ---\n");
    for (int i = 0; i < qtdItensVetor; i++) {
        exibirItem(mochilaVetor[i]);
    }
}

// Busca sequencial no vetor
int buscarSequencialVetor(char* nome) {
    comparacoesSequencial = 0;
    for (int i = 0; i < qtdItensVetor; i++) {
        comparacoesSequencial++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Ordenar vetor por nome (Bubble Sort)
void ordenarVetor() {
    int i, j;
    Item temp;
    for (i = 0; i < qtdItensVetor - 1; i++) {
        for (j = 0; j < qtdItensVetor - i - 1; j++) {
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0) {
                temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }
    printf("Vetor ordenado por nome!\n");
}

// Busca binária (após ordenação)
int buscarBinariaVetor(char* nome) {
    int inicio = 0, fim = qtdItensVetor - 1, meio;
    comparacoesBinaria = 0;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoesBinaria++;
        int cmp = strcmp(nome, mochilaVetor[meio].nome);
        if (cmp == 0) return meio;
        else if (cmp < 0) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

// ========================
// Funções para Lista Encadeada
// ========================

// Inserir na lista
void inserirItemLista(Item novo) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dados = novo;
    novoNo->proximo = mochilaLista;
    mochilaLista = novoNo;
    printf("Item inserido na lista encadeada!\n");
}

// Remover da lista
void removerItemLista(char* nome) {
    No* atual = mochilaLista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) {
                mochilaLista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Item removido da lista!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Item nao encontrado na lista.\n");
}

// Listar lista encadeada
void listarLista() {
    No* atual = mochilaLista;
    printf("\n--- Itens na lista encadeada ---\n");
    while (atual != NULL) {
        exibirItem(atual->dados);
        atual = atual->proximo;
    }
}

// Busca sequencial na lista
No* buscarSequencialLista(char* nome) {
    comparacoesSequencial = 0;
    No* atual = mochilaLista;
    while (atual != NULL) {
        comparacoesSequencial++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// ========================
// Menu principal
// ========================

void menu() {
    int escolhaEstrutura, opcao;
    char nome[30];
    Item novo;
    int pos;
    No* encontrado;

    while (1) {
        printf("\nEscolha a estrutura:\n");
        printf("1 - Vetor\n");
        printf("2 - Lista encadeada\n");
        printf("0 - Sair\n");
        scanf("%d", &escolhaEstrutura);

        if (escolhaEstrutura == 0) break;

        printf("\nMenu de operacoes:\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar sequencial\n");
        if (escolhaEstrutura == 1) {
            printf("5 - Ordenar vetor\n");
            printf("6 - Buscar binaria\n");
        }
        printf("0 - Voltar\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite nome: ");
                scanf(" %[^\n]", novo.nome);
                printf("Digite tipo: ");
                scanf(" %[^\n]", novo.tipo);
                printf("Digite quantidade: ");
                scanf("%d", &novo.quantidade);
                if (escolhaEstrutura == 1) inserirItemVetor(novo);
                else inserirItemLista(novo);
                break;

            case 2:
                printf("Digite nome do item a remover: ");
                scanf(" %[^\n]", nome);
                if (escolhaEstrutura == 1) removerItemVetor(nome);
                else removerItemLista(nome);
                break;

            case 3:
                if (escolhaEstrutura == 1) listarVetor();
                else listarLista();
                break;

            case 4:
                printf("Digite nome do item a buscar: ");
                scanf(" %[^\n]", nome);
                if (escolhaEstrutura == 1) {
                    pos = buscarSequencialVetor(nome);
                    if (pos != -1) {
                        printf("Item encontrado no vetor!\n");
                        exibirItem(mochilaVetor[pos]);
                    } else {
                        printf("Item nao encontrado no vetor.\n");
                    }
                    printf("Comparacoes feitas: %d\n", comparacoesSequencial);
                } else {
                    encontrado = buscarSequencialLista(nome);
                    if (encontrado) {
                        printf("Item encontrado na lista!\n");
                        exibirItem(encontrado->dados);
                    } else {
                        printf("Item nao encontrado na lista.\n");
                    }
                    printf("Comparacoes feitas: %d\n", comparacoesSequencial);
                }
                break;

            case 5:
                if (escolhaEstrutura == 1) ordenarVetor();
                break;

            case 6:
                if (escolhaEstrutura == 1) {
                    printf("Digite nome do item a buscar: ");
                    scanf(" %[^\n]", nome);
                    pos = buscarBinariaVetor(nome);
                    if (pos != -1) {
                        printf("Item encontrado (busca binaria)!\n");
                        exibirItem(mochilaVetor[pos]);
                    } else {
                        printf("Item nao encontrado.\n");
                    }
                    printf("Comparacoes feitas (binaria): %d\n", comparacoesBinaria);
                }
                break;
        }
    }
}

// ========================
// Main
// ========================

int main() {
    menu();
    return 0;
}
