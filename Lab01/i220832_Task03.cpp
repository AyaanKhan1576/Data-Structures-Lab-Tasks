#include <iostream>
using namespace std;

void findMinMax(int* arr, int size, int& max, int& min) {
    max = *arr;
    min = *arr;

    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > max) 
        {
            max = *(arr + i);
        }

        if (*(arr + i) < min) 
        {
            min = *(arr + i);
        }
    }
}
//
//int main() {
//    int size;
//
//    cout << "Enter the size of the array: ";
//    cin >> size;
//
//    int* arr = new int[size];
//
//    cout << "Enter values:" << endl;
//    for (int i = 0; i < size; ++i) {
//        cin >> *(arr + i);
//    }
//
//    cout << "Array elements:" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << *(arr + i) << " ";
//    }
//    cout << endl;
//
//    int max, min;
//    findMinMax(arr, size, max, min);
//
//    cout << "Maximum: " << max << endl;
//    cout << "Minimum: " << min << endl;
//
//    delete[] arr;
//
//    return 0;
//}
