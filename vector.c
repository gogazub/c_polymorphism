#include"vector.h"
#include<stdlib.h>
#include <locale.h>
#include <stdio.h>
#include<assert.h>
#define strLength 16
#define StorageSize 16
vector* Storage[StorageSize];

void CreateNewVector() {
    vector* NewVector;// = (vector*)malloc(sizeof(vector));
    //char name[strLength];
    /*printf("�������� ��� ������");
    scanf_s("%s", NewVector->Name, strLength);*/
    //NewVector->Name = name;
    //fgets(NewVector->Name, strLength, stdin);
    int TypeButton;

    RingInfo* ring = (RingInfo*)(malloc(sizeof(RingInfo)));
    printf("������ ���� �� ������ ������� ������?\n���� ������ ������� ������ ���� int ������� 1\n"
        "���� ������ ������� ������ ���� double ������� 2\n");
    scanf_s("%d", &TypeButton);

    switch (TypeButton) {
    case 1:
        ring = IntRing;
        break;
    case 2:
        ring = DoubleRing;
        break;
    default: return;
    }

    int N;
    printf("������� ����������\n");
    scanf_s("%d", &N);

    printf("������� ���������� ������ �������\n");

    int** ArrInt;
    double** ArrDouble;
    switch (TypeButton) {
    case 1:

        ArrInt = (int**)malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++) {
            ArrInt[i] = (int*)malloc(sizeof(int));
        }
        for (int i = 0; i < N; i++) {
            
            scanf_s("%d", ArrInt[i]);
            int* x = ArrInt[i];
        }
        //for (int i = 0; i < N; i++) printf("%d ", *ArrInt[i]);
        //NewVector = CreateVector(ring, N, (void**)ArrInt);
        NewVector = CreateVectorTest(ring, N, (void*)ArrInt);

        printf("�������� ��� ������\n");
        scanf_s("%s", NewVector->Name, strLength);
        for (int i = 0; i < StorageSize; i++) {
            if (Storage[i] == NULL) {
                Storage[i] = NewVector;
                break;
            }
        }
        break;
    case 2:
        
        ArrDouble = (double**)malloc(sizeof(double*) * N);

        for (int i = 0; i < N; i++) {
            ArrDouble[i] = (double*)malloc(sizeof(double));
        }
        for (int i = 0; i < N; i++) {

            scanf_s("%lf", ArrDouble[i]);

        }
        
        NewVector = CreateVector(ring, N, (void**)ArrDouble);

        printf("�������� ��� ������\n");
        scanf_s("%s", NewVector->Name, strLength);
        for (int i = 0; i < StorageSize; i++) {
            if (Storage[i] == NULL) {
                Storage[i] = NewVector;
                break;
            }
        }
        break;
    }
    printf("������ NewVector\n");
    
    return;
}

void GetInfoAboutVector(int index) {
    printf("\n\n\n\n/ / / / / / / / / / / / / /\n");
    printf("%s ", Storage[index]->Name);

    if (Storage[index]->ring == IntRing) {

        printf("���: Integer\n");

        printf("���������� �������:\n");
        int** arr = (int**)(Storage[index]->coords);
        for (int i = 0; i < Storage[index]->DivN; i++) printf("%d ", *arr[i]);
    }
    if (Storage[index]->ring == DoubleRing) {

        printf("���: Double ");
        double** arr = (double**)(Storage[index]->coords);
        for (int i = 0; i < Storage[index]->DivN; i++) printf("%lf; ", *arr[i]);

    }

    printf("������� -1 ����� ��������� � ������ ��������\n");
    int Button;
    scanf_s("%d", &Button);
    if (Button == -1) return;
    if (Button != -1) scanf_s("%d", &Button);
}

int CheckStorage() {
    int flag = 0;
    for (int i = 0; i < StorageSize; i++) {
        if (Storage[i] == NULL) flag = i;
    }
    /*int i = 0;
        while ((flag == 0) || (i < StorageSize)) {
            if (Storage[i] != NULL) i++;
            else flag = i;
    }*/
    return flag;
}

void GetScalar() {
    printf("\n\n\n\n/ / / / / / / / / / / / / /\n");
    printf("�������� 2 �������, ��� ������� ������ ��������� ��������� ������������\n");
    for (int i = 0; i < StorageSize; i++) {
        if (Storage[i] != NULL) printf("%d) %s\n", i, Storage[i]->Name);
    }
    printf("����� ��������� � ���� ������� -1\n");

    int FirstVectorIndex, SecondVectorIndex;
    
    scanf_s("%d ", &FirstVectorIndex);
    
    scanf_s("%d", &SecondVectorIndex);
    vector* First = Storage[FirstVectorIndex];
    vector* Second = Storage[SecondVectorIndex];
    if (FirstVectorIndex == -1 || SecondVectorIndex == -1) return;
    if (First != NULL) {
        if (Second != NULL) {
            if (First->ring == Second->ring) {

                void* res = ScalarMultiply(First, Second, First->ring->mult, First->ring->sum);
                if (First->ring == IntRing) printf("%d", *(int*)res);
                if (First->ring == DoubleRing) printf("%lf", *(double*)res);
                return;
            }
            printf("���� �������� �� ���������, �������� ������ ���� ");
            scanf_s("%d %d ", &FirstVectorIndex, &SecondVectorIndex);

        }
        scanf_s("%d ", &SecondVectorIndex);

    }
    scanf_s("%d ", &FirstVectorIndex);
}

void OpenStorage() {
    printf("\n\n\n\n/ / / / / / / / / / / / / /\n");
    for (int i = 0; i < StorageSize; i++) {
    if(Storage[i] != NULL) printf("%d) %s\n", i, Storage[i]->Name);
    }
        printf("����� ��������� � ���� ������� -1\n");
    printf("����� ������� ������� �� ��������� - ������� -2\n");
    /*for (int i = 0; i < StorageSize; i++) {
        if (Storage[i] != NULL) printf("%d) %s\n", i, Storage[i]->Name);
    
    }*/
    int TypeButton;
    scanf_s("%d", &TypeButton);

    if (TypeButton == -2) {
        printf("����� ����� �� ������ �������� ������� -2\n");
        int DelButton;
        scanf_s("%d", &DelButton);
        while (DelButton != -2) {
            
            if ((DelButton < 17) && (DelButton > -1)) {
                if (Storage[DelButton] != NULL) {

                    Delete_(Storage[DelButton]);
                    Storage[DelButton] = NULL;
                    printf("\n\n\n\n/ / / / / / / / / / / / / /\n\n\n");
                    for (int i = 0; i < StorageSize; i++) {
                        if (Storage[i] != NULL) printf("%d) %s\n", i, Storage[i]->Name);
                    }
                    scanf_s("%d", &DelButton);
                }
            }
            else scanf_s("%d", &DelButton);
        }
        OpenStorage();

    }

    if ((TypeButton > -1) && Storage[TypeButton] != NULL) {
        GetInfoAboutVector(TypeButton);
        OpenStorage();
    }
    if (TypeButton == -1) return;
    if (!(TypeButton < 16 && TypeButton > -2))scanf_s("%d", &TypeButton);
}

void VecSumWindow() {
    if (CheckStorage() != 0) {
        printf("\n\n\n\n/ / / / / / / / / / / / / /\n");
        printf("�������� 2 �������, ������� ���� �������:\n");

        for (int i = 0; i < StorageSize; i++) {
            if (Storage[i] != NULL) printf("%d) %s\n", i, Storage[i]->Name);
        }
        printf("\n����� ��������� � ���� ������� -1 \n");

        int FirstVectorIndex, SecondVectorIndex;
        scanf_s("%d", &FirstVectorIndex);
        if (FirstVectorIndex == -1) return;
        scanf_s("%d", &SecondVectorIndex);
        if (SecondVectorIndex == -1) return;
        vector* First = Storage[FirstVectorIndex];
        vector* Second = Storage[SecondVectorIndex];
        int j = 0;
        for (int i = 0; i < StorageSize; i++) {
            if (Storage[i] == NULL) {
                j = i;
                break;
            }
        }
        int FreePlace = j;
        
        //if ((FirstVectorIndex == -1) || (SecondVectorIndex == -1)) return;
        if (First != NULL) {
            if (Second != NULL) {
                if (First->ring == Second->ring) {


                    Storage[FreePlace] = VecSum(First, Second, First->ring->sum);

                  


                    printf("������ ����� ������� ������, �������� ���");
                    //char name[strLength];
                    scanf_s("%s", Storage[FreePlace]->Name, strLength);
                    //Storage[FreePlace]->Name = name;
                    return;
                }
                printf("\n���� �������� �� ���������, �������� ������ ����\n");
                scanf_s("%d %d", &FirstVectorIndex, &SecondVectorIndex);

            }
            scanf_s("%d", &SecondVectorIndex);

        }
        scanf_s("%d", &FirstVectorIndex);

    }
    else printf("\n��������� �������� ���������!\n");
}

void Menu() {
    printf("\n\n\n\n/ / / / / / / / / / / / / /\n");
    int MenuButton;
    printf("����� ������� ��� ���� ������ ������� 1\n����� ������� ������ �������� ������� 2\n"
        "����� �������� ��������� ����� ���� �������� ������� 3\n"
        "����� �������� ��������� ������������ ���� �������� ������� 4\n");
    scanf_s("%d", &MenuButton);

    switch (MenuButton) {
    case 1:
        CreateNewVector();
        Menu();
        break;
    case 2:
        OpenStorage();
        Menu();
        break;
    case 3:
        VecSumWindow();
        Menu();
        break;
    case 4:
        GetScalar();
        Menu();
        break;
    default:
        scanf_s("%d", &MenuButton);
    }
}


void Asserts() {
    int arr1[] = {1, 2, 3, 4, 5};
    vector* Vector1 = CreateVector(IntRing, 5, CreateIntArr(arr1, 5));
    //vector* Vector1 = CreateVectorTest(IntRing, 5, (void**)arr1);
    
    printf("Vector1:\n");

    for (int i = 0; i < Vector1->DivN; i++) {
        printf("%d ", *(int*)Vector1->coords[i]);
    }

    printVec(Vector1);
    int arr2[] = {6, 7, 8, 9, 10};
    vector* Vector2 = CreateVector(IntRing, 5, CreateIntArr(arr2, 5));
    printf("Vector2:\n");
    printVec(Vector2);
    double arr3[] = { 1.1, 2.2, 3.3, 4.4};
    vector* Vector3 = CreateVector(DoubleRing, 4, CreateDoubleArr(arr3, 4));
   
    printf("Vector3:\n");
    printVec(Vector3);
    double arr4[] = { 5.5, 6.6, 7.7, 8.8 };
    vector* Vector4 = CreateVector(DoubleRing, 4, CreateDoubleArr(arr4, 4));
    printf("Vector4:\n");
    printVec(Vector4);

    double arr5[] = { 1.0, 2.0, 3.0, 4.0, 5.1 };
    vector* Vector5 = CreateVector(DoubleRing, 5, CreateDoubleArr(arr5, 5));
    printf("Vector5:\n");
    printVec(Vector5);


    printf("������� �������!\n");
    vector* VecSum12 = VecSum(Vector1, Vector2, Vector1->ring->sum);
    vector* VecSum34 = VecSum(Vector3, Vector4, Vector3->ring->sum);
    vector* VecSum13 = VecSum(Vector1, Vector3, Vector1->ring->sum);
    vector* VecSum24 = VecSum(Vector2, Vector4, Vector2->ring->sum);
    vector* VecSum15 = VecSum(Vector1, Vector5, Vector1->ring->sum);

    int VecSumArr12[] = { 7, 9, 11, 13, 15 };
    double VecSumArr34[] = { 6.6, 8.8, 11.0, (8.8 + 4.4)};
    //�������� VecSum
    //1)�������� �������� � ��������� Div � ring
    for (int i = 0; i < VecSum12->DivN; i++) {
        //int** x = (int**)(VecSum12->coords);
        //for (int i = 0; i < 5; i++) printf("%d ", *x[i]);
        assert(VecSumArr12[i] == *(int*)VecSum12->coords[i]);
    }
    for (int i = 0; i < VecSum34->DivN ; i++) {
        double** x = (double**)(VecSum34->coords);
        //for (int i = 0; i < 4; i++) printf("%f ", *x[i]);
        assert(VecSumArr34[i] == *(double*)VecSum34->coords[i]);
        //assert(VecSumArr34[3] == *(double*)VecSum34->coords[3]);
    }
  // 2)�������� ������ Div � ring 
    assert(VecSum13 == NULL);
    assert(VecSum24 == NULL);
    //3)�������� ������ ring 
    assert(VecSum15 == NULL);
    //�������� ScalarMultiply
    //1)������������ �������� � ����������� ring � Div
    assert(*(int*)ScalarMultiply(Vector1, Vector2, Vector1->ring->mult, Vector1->ring->sum) == 130);
    double x = *(double*)ScalarMultiply(Vector3, Vector4, Vector3->ring->mult, Vector3->ring->sum);
    int y = (int)(x * 10.0);
    assert(y == (84.7 * 10));

    //2)������������ �������� � ������� ring � Div
    assert(ScalarMultiply(Vector1, Vector3, Vector1->ring->mult, Vector1->ring->sum) == NULL);
    assert(ScalarMultiply(Vector2, Vector4, Vector2->ring->mult, Vector2->ring->sum) == NULL);
    //3)������������ �������� � ������ ring
    assert(ScalarMultiply(Vector1, Vector5, Vector1->ring->mult, Vector1->ring->sum) == NULL);
    assert(ScalarMultiply(Vector2, Vector5, Vector1->ring->mult, Vector2->ring->sum) == NULL);
    //4)������������ �������� � ������� Div
    assert(ScalarMultiply(Vector3, Vector5, Vector5->ring->mult, Vector5->ring->sum) == NULL);
    assert(ScalarMultiply(Vector4, Vector5, Vector5->ring->mult, Vector5->ring->sum) == NULL);

    Delete_(Vector1);
    Delete_(Vector2);
    Delete_(Vector3);
    Delete_(Vector4);
    Delete_(Vector5);
    return;
}

int main() {
    setlocale(LC_ALL, "Rus");
    for (int i = 0; i < StorageSize; i++) Storage[i] = NULL;
    
    IntRing = Create(sizeof(int), &sumInt, intZeroPtr, &minusInt, &multInt, intOnePtr, printInt, CreateIntArr);
   
    DoubleRing = Create(sizeof(double), &sumD, DZeroPtr, minusD, multD, DOnePtr, printDouble, CreateDoubleArr);
    

    printf("1)������� ����\n2)��������� ����� \n");
    int x;
    scanf_s("%d", &x);
    switch (x)
    {
    case 1:
        Menu();
        break;
    case 2: Asserts();
        break;
    default:
        scanf_s("%d", x);
    }
    
    



}