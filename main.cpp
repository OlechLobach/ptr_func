#include <iostream>
#include <ctime>

using namespace std;

int FindMax(int** array, size_t rows, size_t cols) {
    int max = array[0][0];
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            max = (array[i][j] > max) ? array[i][j] : max;
        }
    }
    return max;
}

int FindMin(int** array, size_t rows, size_t cols) {
    int min = array[0][0];
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            min = (array[i][j] < min) ? array[i][j] : min;
        }
    }
    return min;
}

int FindAverage(int** array, size_t rows, size_t cols) {
    int sum = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            sum += array[i][j];
        }
    }
    return sum / static_cast<float>(rows * cols);
}

template<typename T>
T Action(T** arrayA, T** arrayB, size_t rows, size_t cols, T(*func)(T**, size_t, size_t)) {
    return func(arrayA, rows, cols) + func(arrayB, rows, cols);
}

void GenerateRandomArray(int** array, size_t rows, size_t cols) {
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            array[i][j] = (rand() % 100) + 1;
        }
    }
}

void PrintArray(int** array, size_t rows, size_t cols) {
    cout << "Array:" << endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const size_t rows = 3;
    const size_t cols = 5;

    int** arrayA = new int* [rows];
    int** arrayB = new int* [rows];

    for (size_t i = 0; i < rows; ++i) {
        arrayA[i] = new int[cols];
        arrayB[i] = new int[cols];
    }

    GenerateRandomArray(arrayA, rows, cols);
    GenerateRandomArray(arrayB, rows, cols);

    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            while (arrayB[i][j] == arrayA[i][j]) {
                arrayB[i][j] = (rand() % 100) + 1; 
            }
        }
    }

    PrintArray(arrayA, rows, cols);
    PrintArray(arrayB, rows, cols);

    cout << "Choose an action:" << endl;
    cout << "1. Max" << endl;
    cout << "2. Min" << endl;
    cout << "3. Average" << endl;

    int choice;
    cin >> choice;

    int (*functions[])(int**, size_t, size_t) = { FindMax, FindMin, FindAverage };

    int result = (choice >= 1 && choice <= 3) ? Action(arrayA, arrayB, rows, cols, functions[choice - 1]) : 0;

    cout << "Result: " << result << endl;

    for (size_t i = 0; i < rows; ++i) {
        delete[] arrayA[i];
        delete[] arrayB[i];
    }
    delete[] arrayA;
    delete[] arrayB;

    return 0;
}
