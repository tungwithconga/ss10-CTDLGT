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

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* findMiddle(Node* head) {
    int len = getLength(head);
    int midIndex = len / 2;
    if (len % 2 == 0) {
        midIndex = len / 2;
    } else {
        midIndex = len / 2;
    }

    Node* current = head;
    int index = 0;
    while (current != NULL && index < midIndex) {
        current = current->next;
        index++;
    }

    return current;
}

int main() {
    Node* list = createList();
    Node* mid = findMiddle(list);

    int position = getLength(list) / 2 + (getLength(list) % 2 == 0 ? 1 : 0);
    printf("Node %d: %d\n", position, mid->data);
    return 0;
}
