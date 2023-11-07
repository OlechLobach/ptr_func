#include <iostream>
#include <ctime>
using namespace::std;
const int arraySize = 5;  

int generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

template <typename T>
void calculateSum(const T* arrayA, const T* arrayB, T* arrayC, int size) {
    for (int i = 0; i < size; i++) {
        arrayC[i] = arrayA[i] + arrayB[i];
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int arrayA[arraySize];
    int arrayB[arraySize];
    int arrayC[arraySize];


    for (int i = 0; i < arraySize; i++) {
        arrayA[i] = generateRandomNumber(1, 100);
        arrayB[i] = generateRandomNumber(1, 100);
    }

 
    calculateSum(arrayA, arrayB, arrayC, arraySize);

    cout << "Array A: ";
    for (int i = 0; i < arraySize; i++) {
        cout << arrayA[i] << " ";
    }
    cout << std::endl;

    cout << "Array B: ";
    for (int i = 0; i < arraySize; i++) {
        cout << arrayB[i] << " ";
    }
    cout << std::endl;

    cout << "Array C (Sum of A and B): ";
    for (int i = 0; i < arraySize; i++) {
        cout << arrayC[i] << " ";
    }
    cout << std::endl;

    return 0;
}
