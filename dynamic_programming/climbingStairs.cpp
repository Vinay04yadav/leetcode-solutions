// Problem: Climbing Stairs
// Link: https://leetcode.com/problems/climbing-stairs/description/
// Difficulty: Easy
// Topic: Dynamic Programming

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int prev2 = 1;
        int prev = 2;

        for (int i = 2; i < n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};