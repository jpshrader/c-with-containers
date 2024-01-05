#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

void append(struct LinkedList* list, int val);
void printList(struct LinkedList* list);
void freeList(struct LinkedList* list);
void reverseList(struct LinkedList* list);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("error: must provide a name\n");
        return 1;
    }

    printf("hello, %s!\n", argv[1]);
    printf("let's do some linked list stuff\n");

    struct LinkedList* list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    for (int i = 0; i < 10; i++) {
        append(list, i);
    }

    printList(list);
    reverseList(list);
    printList(list);
    freeList(list);

    return 0;
}

void append(struct LinkedList* list, int val) {
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;

    if (list->head == NULL) {
        list->head = list->tail = n;
    } else {
        list->tail = list->tail->next = n;
    }
}

void reverseList(struct LinkedList* list) {
    struct Node* prev = NULL;
    struct Node* curr = list->head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    list->head = prev;
}

void printList(struct LinkedList* list) {
    struct Node* node = list->head;
    printf("[");
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("]\n");
}

void freeList(struct LinkedList* list) {
    struct Node* head = list->head;
    struct Node* tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}