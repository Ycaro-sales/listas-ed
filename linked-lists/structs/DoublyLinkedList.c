#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "DoublyLinkedList.h"

struct node {
        int item;
        Node *next;
        Node *prev;
};

Node *createDoublyLinkedList() {
        Node *tmp = NULL;

        return tmp;
}

Node *insertNode(Node *node, int item) {
        Node *tmp = malloc(sizeof *tmp);
        tmp->item = item;

        if (node == NULL) {
                tmp->next = NULL;
                return tmp;
        }

        tmp->next = node;

        return tmp;
}

void printDoublyLinkedListForward(Node *first) {
        if (first == NULL) {
                return;
        }

        Node *curr = first;
        int count = 1;

        while (curr != NULL) {
                printf("Node %d:\n", count);
                // printf("\tcharacter:\t%d\n\n", curr->character);
                printf("\titem: %d\n", curr->item);

                count++;

                curr = curr->next;
        }
}

void printDoublyLinkedListBackward(Node *last) {
        if (last == NULL) {
                return;
        }

        Node *curr = last;
        int count = 1;

        while (curr != NULL) {
                printf("Node %d:\n", count);
                // printf("\tcharacter:\t%d\n\n", curr->character);
                printf("\titem: %d\n", curr->item);

                count++;

                curr = curr->prev;
        }
}

int isEmpty(Node *first) { return first == NULL; }

Node *search(Node *first, int item) {
        Node *curr = first;
        Node *searchedNode = NULL;

        while (curr != NULL) {
                if (curr->item == item) {
                        searchedNode = curr;
                        break;
                }

                curr = curr->next;
        }

        return searchedNode;
}
Node *removeNode(Node *first, int item) {
        Node *curr = first;
        Node *removedNode = NULL;

        while (curr->next != NULL) {
                if (curr->next->item == item) {
                        Node *removedNode = curr->next;
                        curr->next = curr->next->next;
                }

                curr = curr->next;
        }

        return NULL;
}

// Questâo 1. Escreva uma função que cria uma lista duplamente encadeada
// circular.
//
void createCircularDoublyLinkedList(Node *first) {
        Node *curr = first;
        if (first == NULL)
                return;

        while (curr->next != NULL)
                curr = curr->next;

        first->prev = curr;
        curr->next = first;
}

// Questão 2. Escreva uma função que ao receber um numero, cria um no
// e o insere de forma ordenada na lista.
// Guarde o ponteiro do elemento inserido para saber
// se na próxima inserção você deve ir para a esquerda ou direita.
//
Node *insertSorted(Node *first, int item) {
        enum direction { left = 0, right };
        Node *tmp = malloc(sizeof *tmp);
        tmp->item = item;
        enum direction direction = left;

        if (first == NULL) {
                tmp->next = NULL;
                tmp->prev = NULL;

                return tmp;
        }

        Node *curr = first;
        int sorted = 0;
        if (first->item == item) {
                tmp->next = first->next;
                tmp->prev = first;
                first->next = tmp;
        } else if (first->item < item) {
                direction = 1;
        } else {
                direction = 0;
        }

        while (1) {
                if (curr->prev == NULL) {
                        curr->prev = tmp;
                        tmp->next = curr;
                        break;
                }

                if (curr->next == NULL) {
                        curr->next = tmp;
                        tmp->prev = curr;
                        break;
                }

                switch (direction) {
                case left:
                        if (curr->prev->item < item) {
                                tmp->prev = curr->prev;
                                tmp->next = curr;
                                curr->prev = tmp;
                                return tmp;
                        }

                        curr = curr->prev;
                        break;
                case right:
                        if (curr->next->item > item) {
                                tmp->next = curr->next;
                                tmp->prev = curr;
                                curr->next = tmp;
                                return tmp;
                        }

                        curr = curr->next;
                        break;
                }
        }

        return tmp;
}
