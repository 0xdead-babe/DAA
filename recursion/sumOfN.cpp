#include <iostream>
using namespace std;

void sum(int i, int s)
{
    if (i < 1)
    {
        cout << "Sum: " << s << endl;
        return;
    }
    sum(i - 1, s + i);
}

int returnSum(int i)
{
    if (i == 1)
        return 1;
    return i + returnSum(i - 1);
}

int main()
{
    int i;
    cout << "Enter number: ";
    cin >> i;
    sum(i, 0);
    cout << "Paramaterised" << endl;
    cout << "Sum: " << returnSum(i) << endl;
    return 0;
}