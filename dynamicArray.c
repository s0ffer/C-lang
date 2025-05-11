#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *pArray;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray(int initialCapacity) {
    DynamicArray *pDA = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (!pDA) return NULL;
    pDA->size=0;
    pDA->capacity=initialCapacity;
    pDA->pArray=(int*)malloc(initialCapacity * sizeof(int));
    return pDA;
}

void put(DynamicArray *pDA, int elem) {
    if (pDA->size >= pDA->capacity) {
        int newCap = (pDA->capacity == 0) ? 1 : pDA->capacity*2;
        int *pNewArr = (int*)malloc(newCap * sizeof(int));
        if (!pNewArr) return;
        for (int i = 0; i < pDA->size; ++i) {
            pNewArr[i] = pDA->pArray[i];
        }
        free(pDA->pArray);
        pDA->pArray = pNewArr;
        pDA->capacity = newCap;
    }
    pDA->pArray[pDA->size++] = elem;
}

void insertAt(DynamicArray *pDA, int index, int elem) {
    if (index < 0 || index > pDA->size) return;

    if (pDA->size >= pDA->capacity) {
        int newCap = (pDA->capacity == 0) ? 1 : (pDA->capacity) * 2;
        int *pNewArr = (int*)malloc(newCap * sizeof(int));

        if (!pNewArr) return;

        for (int i = 0; i < index; ++i) {
            pNewArr[i] = pDA->pArray[i];
        }

        pNewArr[index] = elem;

        for (int i = index; i < pDA->size; ++i) {
            pNewArr[i+1] = pDA->pArray[i];
        }

        free(pDA->pArray);
        pDA->pArray = pNewArr;
        pDA->capacity = newCap;
    } else {
        for (int i = pDA->size; i > index; --i) {
            pDA->pArray[i] = pDA->pArray[i-1];
        }
        pDA->pArray[index] = elem;
    }
    pDA->size++;

}

void removeByIndex(DynamicArray *pDA, int index) {
    if (pDA->size == 0 || index < 0 || pDA->size <= index) return;

    int newCap = (pDA->capacity) - 1;
    int *pNewArr = malloc(newCap * sizeof(int));
    if (!pNewArr) return;
    int j = 0;
    for (int i = 0; i < pDA->size; ++i) {
        if (i == index) {
            continue;
        }
        pNewArr[j++] = pDA->pArray[i];
    }
    free(pDA->pArray);
    pDA->pArray = pNewArr;
    pDA->capacity = newCap;
    pDA->size--;
}

void removeLast(DynamicArray *pDA) {
    if (pDA->size == 0) return;

    pDA->size--;

    if (pDA->capacity > 0 && pDA->size > 0 && pDA->size < pDA->capacity / 4) {
        int newCap = pDA->capacity / 2;
        int *pNewArr = malloc(newCap * sizeof(int));
        if (!pNewArr) return;

        for (int i = 0; i < pDA->size; ++i) {
            pNewArr[i] = pDA->pArray[i];
        }
        free(pDA->pArray);
        pDA->pArray = pNewArr;
        pDA->capacity = newCap;
    }
}

void replace(DynamicArray *pDA, int index, int elem) {
    if (index < 0 || index >= pDA->size) return;
    pDA->pArray[index] = elem;
}

void printArray(DynamicArray *pDA) {
    printf("\n[");
    for (int i = 0; i < pDA->size; ++i) {
        if (i > 0) printf(", ");
        printf("%d", pDA->pArray[i]);
    }
    printf("]");
}

int main(void) {
    DynamicArray *pDA = createDynamicArray(2);
    if (!pDA) {
        printf("Error creating DynamicArray");
        return 1;
    }
    printf("Initialized DynamicArray with: ");
    printf("Elements: %d,  Capacity:  %d, Address:  %p", pDA->size, pDA->capacity, pDA->pArray);

    printf("\n-------------START TEST put() function-------");
    put(pDA, 15);
    printArray(pDA);
    put(pDA, 30);
    put(pDA, 45);
    put(pDA, 99);
    printArray(pDA);
    put(pDA, 74);
    put(pDA, 75);
    printArray(pDA);
    printf("\nElements: %d,  Capacity:  %d, Address:  %p", pDA->size, pDA->capacity, pDA->pArray);
    printf("\n-------------END TEST put() function-------\n");

    printf("\n-------------START TEST removeByIndex(1) function-------");
    printf("\nBefore: ");
    printArray(pDA);
    removeByIndex(pDA, 1);
    printf("\nAfter: ");
    printArray(pDA);
    printf("\nElements: %d,  Capacity:  %d, Address:  %p", pDA->size, pDA->capacity, pDA->pArray);
    printf("\n-------------END TEST removeByIndex(1) function-------\n");

    printf("\n-------------START TEST removeLast() function-------");
    printf("\nBefore: ");
    printArray(pDA);
    removeLast(pDA);
    printf("\nAfter: ");
    printArray(pDA);
    printf("\nElements: %d,  Capacity:  %d, Address:  %p", pDA->size, pDA->capacity, pDA->pArray);
    printf("\n-------------END TEST removeLast() function-------\n");

    printf("\n-------------START TEST replace(index 1, elem 777) function-------");
    printf("\nBefore: ");
    printArray(pDA);
    replace(pDA, 1, 777);
    printf("\nAfter: ");
    printArray(pDA);
    printf("\nElements: %d,  Capacity:  %d, Address:  %p", pDA->size, pDA->capacity, pDA->pArray);
    printf("\n-------------END TEST replace(index 1, elem 777) function-------\n");

    printf("\n-------------START TEST insertAt(index 2, elem 888) function-------");
    printf("\nBefore: ");
    printArray(pDA);
    insertAt(pDA, 2, 888);
    printf("\nAfter: ");
    printArray(pDA);
    printf("\nElements: %d,  Capacity:  %d, Address:  %p", pDA->size, pDA->capacity, pDA->pArray);
    printf("\n-------------END TEST insertAt(index 2, elem 888) function-------\n");

    free(pDA->pArray);
    free(pDA);
    return 0;
}
//
// Created by user on 10.05.2025.
//
