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
    int values[7] = {5, 4, 3, 5, 2, 1, 5};
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 7; i++) {
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

Node* deleteByValue(Node* head, int value) {
    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

Node* printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return head;
}

int main() {
    Node* list = createList();
    int x;
    scanf("%d", &x);
    list = deleteByValue(list, x);
    printList(list);
    return 0;
}
