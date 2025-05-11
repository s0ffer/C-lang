#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *pArray;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray(int initialCapacity) {
    DynamicArray *pDA = (DynamicArray*)malloc(sizeof(DynamicArray));
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

int main(void) {
    DynamicArray *pDA = createDynamicArray(2);
    printf("%d, %d, %p", pDA->size, pDA->capacity, pDA->pArray);

    put(pDA, 15);
    put(pDA, 30);
    put(pDA, 45);
    put(pDA, 45);
    put(pDA, 45);
    put(pDA, 45);
    put(pDA, 45);

    printf("\n%d, %d, %p", pDA->size, pDA->capacity, pDA->pArray);

    free(pDA->pArray);
    free(pDA);
    return 0;
}
//
// Created by user on 10.05.2025.
//
