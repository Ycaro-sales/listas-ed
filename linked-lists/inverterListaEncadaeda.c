#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int item;
    struct no *next;
} NO;

typedef struct lista {
    NO *cabeca;
    int tamanho;
} LISTA;

LISTA *inicializar() {
    LISTA *l = malloc(sizeof(LISTA));
    l->cabeca = NULL;
    l->tamanho = 0;
    return l;
}

NO *criarNo(int item) {
    NO *no = malloc(sizeof(NO));

    no->item = item;
    no->next = NULL;

    return no;
}

void append(LISTA *l, int item) {
    l->tamanho++;

    if (l->cabeca == NULL) {
        l->cabeca = criarNo(item);
        return;
    }

    NO *no = criarNo(item);
    NO *curr = l->cabeca;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = no;
}

void exibirLista(LISTA *l) {
    NO *curr = l->cabeca;

    while (curr != NULL) {
        printf("%d ", curr->item);
        curr = curr->next;
    }
    printf("\n");
}

void inverterLista(LISTA *l) {
}

int main(int argc, char *argv[]) {
    int input;
    
    LISTA *l = inicializar();

    while (scanf("%d", &input) != EOF) {
        append(l, input);
    }
    

    inverterLista(l);
    exibirLista(l);

    return EXIT_SUCCESS;
}
