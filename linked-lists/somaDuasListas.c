#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int digit;
    struct node *next;
} NODE;

typedef struct list {
    NODE *head;
} LIST;

NODE *createNode(int item) {
    NODE *tmp = malloc(sizeof(NODE));

    tmp->digit = item;
    tmp->next = NULL;

    return tmp;
}

void push(LIST *l, int item) {
    NODE *tmp = createNode(item);
    tmp->next = l->head;
    l->head = tmp;
}

LIST *initialize() {
    LIST *tmp = malloc(sizeof(LIST));

    tmp->head = NULL;

    return tmp;
}

LIST *sumLists(LIST *l1, LIST *l2) {
    LIST *sum = initialize();

    int digitSum = 0;

    NODE *currDigit1 = l1->head;
    NODE *currDigit2 = l2->head;

    while (currDigit1 != NULL || currDigit2 != NULL) {
        digitSum += (currDigit1->digit + currDigit2->digit);

        if (digitSum >= 10) {
            push(sum, digitSum % 10);
            digitSum = (digitSum - (digitSum % 10)) / 10;
        } else {
            push(sum, digitSum);
            digitSum = 0;
        }

        currDigit1 = currDigit1->next;
        currDigit2 = currDigit2->next;
    }

    while (currDigit1 != NULL) {
        push(l1, currDigit1->digit);
        currDigit1 = currDigit1->next;
    }

    while (currDigit2 != NULL) {
        push(l2, currDigit2->digit);
        currDigit2 = currDigit2->next;
    }

    return sum;
}

void printList(LIST *l) {
    NODE *curr = l->head;

    while (curr != NULL) {
        printf("%i ", curr->digit);
        curr = curr->next;
    }
}

int main(int argc, char *argv[]) {
    LIST *sum;
    char input;

    LIST *number1 = initialize();
    LIST *number2 = initialize();

    while (input != '+') {
        scanf("%c ", &input);
        push(number1, (int)input);
    }

    while (input != '=') {
        scanf("%c ", &input);
        push(number2, (int)input);
    }

    sum = sumLists(number1, number2);

    printList(sum);

    return EXIT_SUCCESS;
}
