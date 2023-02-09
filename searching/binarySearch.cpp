#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    //searched element was not found;
    if(start > end)
        return -1;

    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binarySearch(arr, start, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, end, key);
    }

}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearch(arr, 0, arrSize-1, 5);
    return 0;
}