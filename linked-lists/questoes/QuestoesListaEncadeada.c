#include "../structs/LinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y)                                                             \
        do {                                                                   \
                typeof(x) temp = (x);                                          \
                (x) = (y);                                                     \
                (y) = temp;                                                    \
        } while (0)

struct node {
        int item;
        char character;
        Node *next;
};

int main(int argc, char *argv[]) { return EXIT_SUCCESS; }

// Questão 1: Dada duas listas encadeadas A e B, escreva
// uma função para verficar se B é um subconjunto de A;
int isBSubsetOfA(Node *A, Node *B) {
        if (A == NULL)
                return 0;

        if (B == NULL)
                return 1;

        int isSubset = 1;

        Node *tmpA = A;
        Node *tmpB = B;

        for (Node *tmpB = B; B != NULL; B = B->next) {
                int currFound = 0;

                for (Node *tmpA = A; A != NULL; A = A->next) {
                        if (tmpA->item == tmpB->item) {
                                currFound = 1;
                                break;
                        }
                }

                if (currFound == 0) {
                        isSubset = 0;
                        break;
                }
        }

        return isSubset;
}

// Questão 2. Escreva uma função para inverter uma lista
//  encadeada usando somente uma “passada” pela lista.
void reverseLinkedList(Node *first) {
        if (!first) {
                return;
        }

        Node *prev = NULL;
        Node *curr = first;
        Node *next = NULL;

        while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;

                if (!next) {
                        first = curr;
                        return;
                }

                curr = next;
        }
}

// Questão 3. Suponha que um texto está armazenado em um
// array onde cada posição contém um caracter. O texto pode conter os
// 256 caracteres da tabela ASCII.
// Escreva uma função para criar uma lista encadeada onde cada
// nó possui o caracter e a sua frequência no texto. Para esta questão,
// navegar pela lista que esta sendo criada é proibido. Lembre-se que para
// inserir um n ́o na lista, podemos ter O(1).

Node *charFrequencyList(char *string) {
        char *characters = calloc(256, sizeof(char));
        Node *tmp = NULL;

        for (int i = 0; i < strlen(string); i++) {
                characters[string[i]]++;
        }

        for (int i = 0; i < 256; i++) {
                if (characters[i] != 0) {
                        tmp = insertNode(tmp, characters[i], (char)i);
                }
        }

        return tmp;
}

// Questão 4. Escreva uma função que ordena em ordem crescente uma lista
// encadeada sem criar uma nova
//  lista.

void sortLinkedList(Node *first) {
        if (first == NULL)
                return;

        Node *curr = first;
        int tmp;

        for (Node *i = first->next; i->next != NULL; i = i->next) {
                for (Node *j = first; j->next != NULL; j = j->next) {
                        if (j->item > j->next->item) {
                                SWAP(j->item, j->next->item);
                        }
                }
        }
}
