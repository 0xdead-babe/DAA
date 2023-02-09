#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int profit;
};

bool cmp(Item a, Item b)
{
    double r1 = a.profit / a.weight;
    double r2 = b.profit / b.weight;
    return r1 > r2;
}

int fractionalKnapSack(Item arr[], int sackCapacity, int arrSize)
{
    sort(arr, arr + arrSize, cmp);
    int filledWeight = 0;
    int profit = 0;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i].weight + filledWeight <= sackCapacity)
        {
            filledWeight += arr[i].weight;
            profit += arr[i].profit;
        }

        else
        {
            int remainingCapacity = sackCapacity - filledWeight;
            profit += remainingCapacity * arr[i].profit / arr[i].weight;
            break;
        }
    }

    return profit;
}

int main()
{
    int n;
    cin >> n;
    Item item[n];
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].profit;
    }
    cout << "Profit: " << fractionalKnapSack(item, 60, n);
}
