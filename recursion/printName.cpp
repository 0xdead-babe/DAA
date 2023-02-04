#include <iostream>
using namespace std;

// global variable to keep track of count
int count = 0;

void printName()
{
    if (count == 5)
        return;
    cout << "Genuine Panthi" << endl;
    count++;
    printName();
}

int main()
{
    printName();
    return 0;
}