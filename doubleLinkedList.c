#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* pNext;
    struct Node* pPrev;
} Node;

typedef struct {
    Node* pHead;
    Node* pTail;
} myLinkedList;

myLinkedList* createLinkedList() {
    myLinkedList* pToList = (myLinkedList*)malloc(sizeof(myLinkedList));
    pToList->pHead = NULL;
    pToList->pTail = NULL;
    return pToList;
}

Node* createNewNode(int value) {
    Node* pNewNode = malloc(sizeof(Node));
    pNewNode->data = value;
    pNewNode->pNext = NULL;
    pNewNode->pPrev = NULL;
    return pNewNode;
}

int insertAtHead(myLinkedList* pToList, int value) {
    if (!pToList) return 1; // Checking for list is not created

    // Creating new node
    Node* pToNewNode = createNewNode(value);

    // If list is empty, then new node it's head now
    if (pToList->pHead == NULL) {
        pToList->pHead = pToNewNode;
        pToList->pTail = pToNewNode;
        return 0;
    };

    // If list not empty, then assigning newNode next's is current Head
    pToNewNode->pNext = pToList->pHead;
    pToList->pHead->pPrev = pToNewNode; // old HEAD prev is now new node | HEAD -> NULL <-newNode -> <- oldHead -> NULL
    pToList->pHead = pToNewNode; // pointer for head now stores newNode's address

    return 0;
}

int insertAtTail(myLinkedList* pToList, int value) {
    if (!pToList) return 1; // check for not defined list

    // if HEAD is NULL, then we call insertAtHead function
    if (pToList->pHead == NULL) {
        insertAtHead(pToList, value);
        return 0;
    }

    // create new node
    Node* pToNewNode = createNewNode(value);

    // we assume that HEAD is not NULL, but if TAIL is NULL, then we define fix links between HEAD and new TAIL
    if (pToList->pTail == NULL) {
        pToNewNode->pPrev = pToList->pHead;
        pToList->pHead->pNext = pToNewNode;
    } else { // if TAIL is not NULL, then fixing links with previous TAIL
        pToNewNode->pPrev = pToList->pTail;
        pToList->pTail->pNext = pToNewNode;
    }
    pToList->pTail = pToNewNode; // define new node is TAIL
    return 0;
}

// recursive function for printing values of nodes
int printList(Node* pHead) {
    if (pHead == NULL) {
        printf("List is empty.\n");
        return 1;
    }

    if (pHead->pNext == NULL) { // stop condition for recursion
        printf("%d\n", pHead->data);
        return 0;
    }
    printf("%d ", pHead->data);
    printList(pHead->pNext); // recursion call back to this function with next node as argument
    return 0;
};

int main(void) {
    myLinkedList* pToList = createLinkedList();

    printList(NULL);

    printf("\n-------------------------Insert at HEAD---------------------------\n");
    insertAtHead(pToList, 2); // 2
    printList(pToList->pHead);
    printf("Current head n tail: %d, %p\n", pToList->pHead->data, pToList->pTail);

    insertAtHead(pToList, 8); // 8, 2
    printList(pToList->pHead);
    printf("Current head n tail: %d, %d\n", pToList->pHead->data, pToList->pTail->data);

    insertAtHead(pToList, 5); // 5, 8, 2
    printList(pToList->pHead);
    printf("Current head n tail: %d, %d\n", pToList->pHead->data, pToList->pTail->data);

    insertAtHead(pToList, 1); // 1, 5, 8, 2
    printList(pToList->pHead);
    printf("Current head n tail: %d, %d\n", pToList->pHead->data, pToList->pTail->data);

    printf("\n-------------------------Insert at TAIL---------------------------\n");

    insertAtTail(pToList, 99); // 1, 5, 8, 2, 99
    printList(pToList->pHead);
    printf("Current head n tail: %d, %d\n", pToList->pHead->data, pToList->pTail->data);

    insertAtTail(pToList, 88); // 1, 5, 8, 2, 99, 88
    printList(pToList->pHead);
    printf("Current head n tail: %d, %d\n", pToList->pHead->data, pToList->pTail->data);

    printf("----------------------------------------------------------------\n");

    free(pToList);
    return 0;
}