#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char palavra[15];
    struct cel *proximo;
} cel; 

cel* criarNo(const char *palavra) {
    cel* nova = (cel*)malloc(sizeof(cel));
    strncpy(nova->palavra, palavra, 14);
    nova->palavra[14] = '\0';
    nova->proximo = NULL;
    return nova;   
}

void inserir(cel** head, const char* palavra, const char *condicao) {
    cel* nova = criarNo(palavra);

    if (*head == NULL) {
        *head = nova;
        return;
    }

    cel* atual = *head;
    cel* anterior = NULL;

    if (condicao == NULL || strcmp(condicao, "nao") == 0 || strlen(condicao) == 0) {
        // Adicionar no final
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = nova;
    } else {
        // Inserir antes do nó que contém `condicao` ou no final
        while (atual != NULL && strcmp(atual->palavra, condicao) != 0) {
            anterior = atual;
            atual = atual->proximo;
        }
        
        if (atual == NULL) {
            anterior->proximo = nova;  // `condicao` não encontrada, adiciona no final
        } else if (anterior == NULL) {
            nova->proximo = *head;     // `condicao` está no primeiro nó
            *head = nova;
        } else {
            nova->proximo = atual;     // Insere antes do nó com `condicao`
            anterior->proximo = nova;
        }
    }
}

void imprimirLista(const cel* head) {
    const cel* atual = head;
    while (atual != NULL) {
        printf("%s", atual->palavra);
        atual = atual->proximo;
        if (atual != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

void limpar(cel* head) {
    while (head != NULL) {
        cel* temp = head;
        head = head->proximo;
        free(temp);
    }
}

int main() {
    cel *Head = NULL;
    char *condicao = NULL;

    for (int i = 0; i < 2; i++) {
        char nomes[100];
        fgets(nomes, sizeof(nomes), stdin);

        if (i == 1) {
            condicao = malloc(15 * sizeof(char));
            fgets(condicao, 15, stdin);
            condicao[strcspn(condicao, "\n")] = '\0';
        }
        
        char *token = strtok(nomes, " \n");
        while (token != NULL) {
            inserir(&Head, token, condicao);
            token = strtok(NULL, " \n");
        }
    }

    imprimirLista(Head);

    free(condicao);
    limpar(Head);

    return 0;
}
