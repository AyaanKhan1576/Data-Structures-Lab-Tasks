#include<iostream>
using namespace std;

int* multiplication(int* matrix1, int* matrix2, int rows, int cols) 
{
    int* final = new int[rows * cols] {0};


    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            for (int k = 0; k < cols; ++k) 
            {
                *(final + j + (i * cols)) += *(matrix1 + k + (i * cols)) * *(matrix2 + j + (k * cols));
            }
        }
    }

    return final;
}

int* addition(int* matrix1, int* matrix2, int rows, int cols) 
{
    int* final = new int[rows * cols];

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            *(final + j + (i * cols)) = *(matrix1 + j + (i * cols)) + *(matrix2 + j + (i * cols));
        }
    }

    return final;
}
//
//int main()
//{
//    int rows = 3;
//    int cols = 3;
//
//    int* matrix1 = new int[rows * cols];
//    int* matrix2 = new int[rows * cols];
//
//    cout << "Enter values for matrix 1" << endl;
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < cols; j++) 
//        {
//            cin >> *(matrix1 + j + (i * cols));
//        }
//    }
//
//    cout << "Enter values for matrix 2" << endl;
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < cols; j++) 
//        {
//            cin >> *(matrix2 + j + (i * cols));
//        }
//    }
//
//    cout << "matrix 1" << endl;
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < cols; j++) 
//        {
//            cout << *(matrix1 + j + (i * cols)) << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "matrix 2" << endl;
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < cols; j++) 
//        {
//            cout << *(matrix2 + j + (i * cols)) << " ";
//        }
//        cout << endl;
//    }
//
//    int* additionMatrix = addition(matrix1, matrix2, rows, cols);
//    
//    cout << "Addition Result\n";
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            cout << *(additionMatrix + j + (i * cols))<<" ";
//        }
//        cout << endl;
//    }
//
//    int* multMatrix = multiplication(matrix1, matrix2, rows, cols);
//
//    cout << "Multiplication Result\n";
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            cout<< *(multMatrix + j + (i * cols))<<" ";
//        }
//        cout << endl;
//    }
//
//	return 0;
//}






