// Problem: Best time to buy and sell stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Difficulty: Easy
// Topic: Arrays

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int minEle = prices[0];
        int profit = 0;

        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - minEle;
            profit = max(profit, cost);
            minEle = min(minEle, prices[i]);
        }

        return profit;
    }
};