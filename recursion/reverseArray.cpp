#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int l, int r)
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverseArray(arr, l + 1, r - 1);
}

void reverseArraySinglePointer(int arr[], int i, int arrSize)
{
    if (i > arrSize - i - 1) //alternative base case (i >= arrSize / 2)
        return;
    swap(arr[i], arr[arrSize - i - 1]);
    reverseArraySinglePointer(arr, i + 1, arrSize);
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
    int arr[] = {1, 4, 5, 6, 10};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    // reverseArray(arr, 0, arraySize - 1);
    reverseArraySinglePointer(arr, 0, arraySize);
    printArray(arr, arraySize);
    return 0;
}