#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int item;
    struct no *prox;
} NO;

typedef struct {
    NO *cabeca;
    int tamanho;
} LISTA;

LISTA *inicializar() {
    LISTA *l = (LISTA *)malloc(sizeof(LISTA));

    l->cabeca = NULL;
    l->tamanho = 0;

    return l;
}

void imprimir(LISTA *l) {
    NO *curr = l->cabeca;
    while (curr->prox != NULL) {
        printf("%d ", curr->item);
        curr = curr->prox;
    }
}

void append(LISTA *l, int item) {
    NO *tmp = (NO *)malloc(sizeof(NO));

    tmp->item = item;
    tmp->prox = NULL;

    NO *curr = l->cabeca;

    while (curr->prox != NULL)
        curr = curr->prox;

    curr->prox = tmp;
}
void preencherLista(LISTA *l) {
    int input;

    while (1) {
        scanf("%d ", &input);
        append(l, input);

        if (input == EOF) {
            break;
        }
    }
}

void inverter(LISTA *l) {
    NO *prev = NULL;
    NO *curr = l->cabeca;
    NO *prox = l->cabeca->prox;

    while (curr->prox != NULL) {
        curr->prox = prev;
        prev = curr;
        curr = prox;
        prox = curr->prox;
    }
    curr->prox = prev;
}

int main() {
    LISTA *l = inicializar();

    preencherLista(l);
    inverter(l);
    imprimir(l);

    return 0;
}
