/*
        DoublyLinkedList.h
        TAD para representar uma Lista Duplamente Encadeada.
*/
typedef struct node Node;

Node *createDoublyLinkedList();
Node *insertNode(Node *node, int item);

void printDoublyLinkedListForward(Node *first);
void printDoublyLinkedListBackward(Node *last);

int isEmpty(Node *first);

Node *search(Node *first, int item);
Node *removeNode(Node *first, int item);
