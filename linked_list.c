#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtHead(Node** head, int data) {
    Node* newHead = createNode(data);
    newHead->next = *head;
    *head = newHead;
}

void insertAtTail(Node* head, int data) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);;
}

Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("\nFound element by value %d in node: %p", data, temp);
            return temp;
        }
        temp = temp->next;
    }
    printf("\nElement %d not found in nodes", data);
    return NULL;
}

int length(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void freeList(Node* head) {
    Node* prevNode = NULL;
    while (head != NULL) {
        prevNode = head;
        head = head->next;
        printf("\nFreeing node %d, %p", prevNode->data, prevNode->next);
        free(prevNode);
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("\nElement %d Address: %p", temp->data, (void*)temp->next);
        temp = temp->next;
    }
}

int main(void) {
    Node* head = createNode(1);
    // printf("%d, %p", head->data, head->next);

    insertAtHead(&head, 777);
    insertAtHead(&head, 555);
    insertAtTail(head, 888);
    insertAtTail(head, 321);
    printList(head);

    search(head, 888);

    printf("\nLength of list is: %d", length(head));

    freeList(head);
    // free(head);
    return 0;
}
//
// Created by user on 12.05.2025.
//
