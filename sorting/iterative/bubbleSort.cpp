#include <iostream>
#include <algorithm>
using namespace std;

/*
** Outer loop runs upto arrSize-1
** at first pass biggest element will be at last index
** therefore, no  need to iterate upto that index

** Some part of array will be sorted after each pass
** therefore no need to iterate through them
** instead we iterate upto arrSize-i-1
*/

void bubbleSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
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
    bubbleSort(arr, arrSize);
    printArray(arr, arrSize);
    return 0;
}