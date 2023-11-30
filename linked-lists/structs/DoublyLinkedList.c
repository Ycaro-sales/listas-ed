#include "DoublyLinkedList.h"

struct node {
        int item;
        Node *next;
        Node *prev;
};

Node *createDoublyLinkedList() {}

Node *insertNode(Node *node, int item);

void printDoublyLinkedListForward(Node *first);
void printDoublyLinkedListBackward(Node *last);

int isEmpty(Node *first);

Node *search(Node *first, int item);
Node *removeNode(Node *first, int item);

// Questâo 1. Escreva uma função que cria uma lista duplamente encadeada
// circular.

// Questão 2. Escreva uma função que ao receber um numero, cria um no
// e o insere de forma ordenada na lista.
// Guarde o ponteiro do elemento inserido para saber
// se na próxima inserção você deve ir para a esquerda ou direita.
