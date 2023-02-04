#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(int arr[], int arrSize)
{
    int value, hole;
    for (int i = 1; i <= arrSize - 1; i++)
    {
        value = arr[i];
        hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            // shift towards right
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {2, 4, 9, 8, 6, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, arrSize);
    printArray(arr, arrSize);
    return 0;
}