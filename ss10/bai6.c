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
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

Node* findMiddle(Node* head) {
    int length = getLength(head);
    int midIndex = length / 2;

    Node* current = head;
    for (int i = 0; i < midIndex; i++) {
        current = current->next;
    }

    return current;
}

int main() {
    Node* list = createList();
    Node* middle = findMiddle(list);

    int length = getLength(list);
    int position = length / 2 + (length % 2 == 0 ? 1 : 0);
    printf("Node %d: %d\n", position, middle->data);

    return 0;
}
