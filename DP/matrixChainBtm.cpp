#include <iostream>

using namespace std;

#define MAX 100

int DP[MAX][MAX];

int matrixChain(int dimension[], int dimensionSize)
{
    // initialization
    for (int i = 1; i <= dimensionSize; i++)
        DP[i][i] = 0;
    // ie c[1,1] = 0

    for (int i = dimensionSize; i >= 1; i--)
    {
        for (int j = i + 1; j <= dimensionSize; j++)
        {
            int minCost = 1e9;
            for (int k = i; k < j; k++)
            {
                int cost = DP[i][k] + DP[k + 1][j] + dimension[i - 1] * dimension[k] * dimension[j];
                cout << "i, j: " << i << " " << j << " " << cost << endl;
                if (cost < minCost)
                    minCost = cost;
            }
            DP[i][j] = minCost;
        }
    }

    return DP[1][dimensionSize];
}

int main()
{
    int dimensionLength;
    cin >> dimensionLength;
    int dimensionArray[dimensionLength];
    for (int i = 0; i < dimensionLength; i++)
        cin >> dimensionArray[i];
    cout << matrixChain(dimensionArray, dimensionLength - 1);
    return 0;
}