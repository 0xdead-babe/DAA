#include <iostream>
using namespace std;

void print(int count, int n)
{
    if (count > n)
        return;
    cout << count << endl;
    print(count + 1, n);
}

void printBack(int count, int n)
{
    if (count < 1)
        return;
    cout << count << endl;
    printBack(count - 1, n);
}

void backTrack(int count, int n)
{
    if (count < 1)
        return;
    backTrack(count - 1, n);
    cout << count << endl;
}

void printBackBackTrack(int count, int n)
{
    if (count > n)
        return;
    printBackBackTrack(count + 1, n);
    cout << count << endl;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    print(1, n);
    cout << "Printing backward" << endl;
    printBack(n, n);
    cout << "Back tracking" << endl;
    backTrack(n, n);
    cout<<"Print backward using backtrack"<<endl;
    printBackBackTrack(1,n);
    return 0;
}