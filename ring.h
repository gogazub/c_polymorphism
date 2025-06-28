#pragma once
#include<stdlib.h>

typedef struct
{
    size_t size;
    void* (*sum)(void*, void*);
    void* zero;
    void* (*minus)(void*);
    void* (*mult)(void*, void*);
    void* one;
    void* (*Print)(void*);
    void** (*CreateArr)(void*, int*);
}RingInfo;

RingInfo* IntRing;
RingInfo* DoubleRing;

RingInfo* Create(size_t size_, void* (*sum_)(void*, void*), void* zero_, void* (*minus_)(void*), void* (*mult_)(void*, void*), void* one_, void* (*Print)(void*), void** (*CreateArr)(void*, int*)) {
    RingInfo* obj = (RingInfo*)malloc(sizeof(RingInfo));
    obj->size = size_;
    obj->sum = sum_;
    obj->zero = zero_;
    obj->minus = minus_;
    obj->mult = mult_;
    obj->one = one_;
    obj->Print = Print;
    obj->CreateArr = CreateArr;
    return obj;
}



void* sumInt(void* a1, void* a2) {
    int* ia1 = (int*)a1;
    int* ia2 = (int*)a2;
    int* res = malloc(sizeof(int));
    *res = *ia1 + *ia2;
    return (void*)res;
}
void* minusInt(void* a1) {
    int* ia1 = (int*)a1;
    int* res = (int*)malloc(sizeof(int));
    *res = (*ia1 * -1);
    return (void*)res;
}
void* multInt(void* a1, void* a2) {
    int* test = (int*)IntRing->zero;
    int* da1 = (int*)a1;
    int* da2 = (int*)a2;
    int* res = (int*)malloc(sizeof(int));
    *res = (*da1 * *da2);
    return (void*)res;
}
void* sumD(void* a1, void* a2) {
    double* ia1 = (double*)a1;
    double* ia2 = (double*)a2;
    double* res = (double*)malloc(sizeof(double));
    *res = *ia1 + *ia2;
    return (void*)res;
}
void* minusD(void* a1) {
    double* ia1 = (double*)a1;
    double* res = (double*)malloc(sizeof(double));
    *res = (*ia1 * -1.0);
    return (void*)res;
}
void* multD(void* a1, void* a2) {
    double* da1 = (double*)a1;
    double* da2 = (double*)a2;
    double* res = (double*)malloc(sizeof(double));
    *res = *da1 * *da2;
    return (void*)res;
}

int intOne = 1;
int intZero = 0;
int* intOnePtr = &intOne;
int* intZeroPtr = &intZero;
double DOne = 1.0;
double DZero = 0.0;
double* DOnePtr = &DOne;
double* DZeroPtr = &DZero;


 
void printInt(void* a){
    printf("%d", *(int*)a);
    return;
}
void printDouble(void* a) {
    printf("%.1f", *(double*)a);
    return;
}

void** CreateIntArr(int arr[], int N) {
    void** Arr = (void**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        Arr[i] = (void*)malloc(sizeof(int*));
    }
    for (int i = 0; i < N; i++) {
        Arr[i] = (void*)&arr[i];
        //int* x = (int*)Arr[i];
        //int y = *x;
    }

    return Arr;

}

void** CreateDoubleArr(double arr[], int N) {
    void** Arr = (void**)malloc(sizeof(double*) * N);
    for (int i = 0; i < N; i++) {
        Arr[i] = (void*)malloc(sizeof(double*));
    }
    for (int i = 0; i < N; i++) {
        Arr[i] = (void*)&arr[i];
        /*printf("%lf", *(int*)Arr[i]);*/
    }
    return Arr;

}



