// Problem: Frog Jump
// Link: https://www.naukri.com/code360/problems/frog-jump_3621012?count=25&search=frog%20jump&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav
// Difficulty: Easy
// Topic: Dynamic Programming

#include <bits/stdc++.h>
int func(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int left = func(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = func(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int> dp(n+1, -1);

    // if using memoization:
    // return func(n-1, heights, dp); // here n-1 because we are following 0 based indexing for the stairs, 0 index -> 1st stair

    // using tabular thing
    // dp[0] = 0;
    // for(int i = 1; i < n; i++){
    //     int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
    //     int ss = INT_MAX;
    //     if(i > 1){
    //         ss = dp[i-2] + abs(heights[i] - heights[i-2]);
    //     }

    //     dp[i] = min(fs, ss);
    // }

    // return dp[n-1];

    // more space optimization on tabular

    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
        {
            ss = prev2 + abs(heights[i] - heights[i - 2]);
        }

        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}