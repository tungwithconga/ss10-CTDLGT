#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

Node* createList() {
    int values[5] = {5, 4, 3, 2, 1};
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 5; i++) {
        Node* newNode = createNode(values[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

Node* printData(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("data: %d\n", current->data);
        current = current->next;
    }
    return head;
}

int main() {
    Node* list = createList();
    printData(list);
    return 0;
}
