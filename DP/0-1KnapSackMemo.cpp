#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100

// global variable for wt and their associated profit
int WT[MAX];
int VAL[MAX];
// matrix to keep track of recursive calls
int DP[MAX][MAX];

int knapSack(int n, int w)
{
    // n -> no of elements in an array
    // w -> capacity of knapsack

    // if now elements in an array or capacity of knapsack is 0
    if (n == 0 || w == 0)
        return 0;

    // check if there is already calculated value
    if (DP[n][w] != -1)
        return DP[n][w];

    if (WT[n - 1] > w)
        return DP[n][w] = knapSack(n - 1, w);

    return max(VAL[n - 1] + knapSack(n - 1, w - WT[n - 1]), knapSack(n - 1, w));
}

int main()
{
    int n, w;
    cout << "Enter number of items and capacity: ";
    cin >> n >> w;
    cout << endl;
    cout << "Enter value and their weight" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> VAL[i] >> WT[i];
    }
    memset(DP, -1, sizeof(DP));

    cout << knapSack(n, w);
    return 0;
}