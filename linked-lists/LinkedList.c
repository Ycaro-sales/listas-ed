#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
        int item;
        Node *next;
};

Node *createLinkedList() {
        Node *tmp = NULL;

        return tmp;
};

Node *insertNode(Node *node, int item) {
        Node *tmp = malloc(sizeof *tmp);
        tmp->item = item;

        if (node == NULL) {
                tmp->next = NULL;
                return tmp;
        }

        tmp->next = node;

        return tmp;
};

void printLinkedList(Node *first) {
        if (first == NULL) {
                return;
        }

        Node *curr = first;
        int count = 1;

        while (curr != NULL) {
                printf("item %d:\t%d\n", count, curr->item);
                count++;
                curr = curr->next;
        }
}

int isEmpty(Node *first) { return first == NULL; };

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
};
Node *removeNode(Node *first, int item) {
        Node *curr = first;
        Node *removedNode = NULL;

        while (curr != NULL) {
                if (curr->next->item == item) {
                        Node *removedNode = curr->next;
                        curr->next = curr->next->next;
                        return removedNode;
                }

                curr = curr->next;
        }

        return NULL;
}
