// Problem: Fractional Knapsack
// Link:
// Difficulty: Easy
// Topic: Greedy Algorithm

#include <bits/stdc++.h>
bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    double r1 = double(a.second) / a.first;
    double r2 = double(b.second) / b.first;

    if (r1 > r2)
        return true;
    else
        return false;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), comparator);
    double totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= w)
        {
            totalValue += items[i].second;
            w -= items[i].first;
        }
        else
        {
            totalValue += (double(items[i].second) / items[i].first) * w;
            break;
        }
    }
    return totalValue;
}