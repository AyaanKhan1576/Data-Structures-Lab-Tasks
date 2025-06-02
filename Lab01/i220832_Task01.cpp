#include<iostream>
using namespace std;

void removeDuplicates(int* arr, int& size)
{
	int* arr2 = new int[size];
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int count3 = 2;
		int count4 = 1;
			if (*(arr + i) != *(arr + i + 1))
			{
				*(arr2 + count++) = *(arr + i);
				count2++;
				//i++;
			}

			else
			{
				*(arr2 + count++) = *(arr + i);
				while (*(arr + i) == *(arr + i + count3++))
				{
					count4++;
				}
				
				i += count4;
				count2++;
				//size--;
			}
	}

	size = count2;
	for (int i = 0; i < count2; i++)
	{
		*(arr + i) = *(arr2 + i);
		//cout << *(arr + i) << endl;
	}
	//cout << endl;
}


int main()
{
	int size;
	cout << "intput size of array\n";
	cin >> size;

	int* arr = new int[size];

	cout << "Enter values\n";

	for (int i = 0; i < size; i++)
	{
		cin >> *(arr + i);
	}
	
	cout << endl;
	removeDuplicates(arr, size);

	int count = 0;
	while ((count) < size)//(arr + count) != NULL)
	{
		cout << *(arr + count) << endl;
		count++;
	}

	return 0;
}