#pragma once
#include<stdlib.h>
#include "ring.h"
#define MAX_LENGTH 16
typedef struct vector
{
    char Name[MAX_LENGTH];
    RingInfo* ring;
    int DivN;
    void** coords;
}vector;



vector* VecSum(vector* a1, vector* a2, void* (*sum)(void*, void*))
{
    vector* res = (vector*)malloc(sizeof(vector));
    res->DivN = a1->DivN;
    res->ring = a1->ring;
    if ((a1->DivN != a2->DivN) || (a1->ring != a2->ring) ) return NULL;
    res->coords = malloc(sizeof(a1->coords));
    
    void** Arr1 = a1->coords;
    void** Arr2 = a2->coords;
    void** ResultArr = res->coords;

    for (int i = 0; i < a1->DivN; i++) {
        ResultArr[i] = malloc(sizeof(int*));
        
        int* x = (int*)Arr1[i];
        int* y = (int*)Arr2[i];
        
        ResultArr[i] = sum(Arr1[i], Arr2[i]);
        
        int* z = (int*)ResultArr[i];
        int f = *z;
    }
   
   // for (int i = 0; i < a1->DivN; i++)printf("%d \n", *(int*)res->coords[i]);

    return res;
   

}

void* ScalarMultiply(vector* a1, vector* a2, void* (*multiply)(void*, void*), void* (*sum)(void*, void*)) {
    if ((a1->DivN != a2->DivN) || (a1->ring != a2->ring)) return NULL;
    void* res = malloc(a1->ring->size);
    res = a1->ring->zero;
    //int* x = (int*)res;
    void** Arr1 = (a1->coords);
    void** Arr2 = (a2->coords);
    int* x = (int*)Arr1[0];
    for (int i = 0; i < a1->DivN; i++) {
        int* y = (int*)Arr1[i];
        int* z = (int*)Arr2[i];
        res = sum(res, multiply(Arr1[i], Arr2[i]));
        int* x = (int*)res;
    }
    
    return res;
}

vector* CreateVector(RingInfo* ring_, int Div, void* arr[]) 
{
    vector* newVec = (vector*)malloc(sizeof(vector));
    newVec->ring = ring_;
    newVec->DivN = Div;
    newVec->coords = arr;
    
    return newVec;
}

vector* CreateVectorTest(RingInfo* ring_, int Div, void* arr) {
    
    vector* newVec = (vector*)malloc(sizeof(vector));
    newVec->ring = ring_;
    newVec->DivN = Div;

    //for (int i = 0; i < 4; i++) printf("%d ", *((int**)arr)[i]);
    newVec->coords = (void**)arr;
   // newVec->coords = newVec->ring->CreateArr(arr, Div);

   // for (int i = 0; i < 4; i++) printf("%d ", *(int*)newVec->coords[i]);

    //newVec->coords = arr;
    return newVec;
}


void Delete_(vector* vec) {
    free(vec->coords);
    free(vec);
  
        return;
}






void printVec(vector* vec) {
    if (vec->ring == IntRing) {
        printf("Тип: int\n");
    }
    if (vec->ring == DoubleRing) {
        printf("Тип: double\n");
    }

    printf("DivN: %d\n", vec->DivN);
    printf("Координаты: \n");
    for (int i = 0; i < vec->DivN; i++) {
        vec->ring->Print(vec->coords[i]);
        printf(" ");
    }
    printf("\n\n");
    return;
}