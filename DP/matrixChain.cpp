// memoized code
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100

int DP[MAX][MAX];

// formula
//  c[i, j] = c[i, k] + c[k+1, j] + d(i-1) * d(k) * d(j)

int matrixChain(int dimension[], int i, int j)
{
    // base condition
    if (i == j) // ie c[1,1] == 0
        return 0;
    if (DP[i][j] != -1)
        return DP[i][j];
    int minCost = 1e9;
    for (int k = i; k < j; k++)
    {
        int cost = matrixChain(dimension, i, k) + matrixChain(dimension, k + 1, j) + dimension[i - 1] * dimension[k] * dimension[j];
        if (cost < minCost)
            minCost = cost;
    }
    DP[i][j] = minCost;
    return minCost;
}

int main()
{
    int dimensionLength;
    cin >> dimensionLength;
    int dimensionArray[dimensionLength];
    memset(DP, -1, sizeof(DP));
    for (int i = 0; i < dimensionLength; i++)
        cin >> dimensionArray[i];
    cout << matrixChain(dimensionArray, 1, dimensionLength - 1);
    return 0;
}