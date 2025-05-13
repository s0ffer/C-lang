#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int len(Node* node);

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

int insertAtIndex(Node** head, int index, int data) {
    int lengthList = len(*head);

    if (index > lengthList) return 1;

    if (index == lengthList) {
        insertAtTail(*head, data);
        return 0;
    }

    if (index == 0) {
        insertAtHead(head, data);
        return 0;
    }

    int i = 0;
    Node* current = *head;
    while (current != NULL) {
        if (i == index-1) {
            Node* newNode = createNode(data);
            newNode->next = current->next;
            current->next = newNode;
            return 0;
        }
        current = current->next;
        i++;
    }
    return 1;
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

int removeByValue(Node** head, int value) {
    if (head == NULL) return 0;

    Node* prev = NULL;
    Node* current = *head;
    while (current != NULL) {
        if (current->data == value) {
            if (current == *head) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;
}


int len(Node* head) {
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

    // search(head, 888);
    //
    // printf("\nLength of list is: %d\n", len(head));
    //
    // printList(head);
    // printf("\n");
    // insertAtIndex(&head, 2, 666);
    // insertAtIndex(&head, 4, 444);
    // insertAtIndex(&head, 7, 652);
    // printf("\n");
    // printList(head);

    printf("\n");

    // removeByValue(&head, 888);
    // removeByValue(&head, 777);
    removeByValue(&head, 555);
    printList(head);
    printf("\n__________________");

    freeList(head);
    // free(head);
    return 0;
}
//
// Created by user on 12.05.2025.
//
