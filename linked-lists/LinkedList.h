/*
        LinkedList.h
        TAD para representar uma Lista Encadeada .
*/
typedef struct node Node;

Node *createLinkedList();
Node *insertNode(Node *node, int item);

void printLinkedList(Node *first);
int isEmpty(Node *first);

Node *search(Node *first, int item);
Node *removeNode(Node *first, int item);
