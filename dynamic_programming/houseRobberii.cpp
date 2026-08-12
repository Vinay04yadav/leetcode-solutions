// Problem: House Robber II
// Link: https://leetcode.com/problems/house-robber-ii/description/
// Difficulty: Medium
// Topic: Dynamic Programming

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n - 1; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += prev2;
            }
            int nonTake = prev;

            int curr = max(take, nonTake);

            prev2 = prev;
            prev = curr;
        }

        int pREV = nums[1];
        int pREV2 = 0;

        for (int i = 2; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += pREV2;
            }
            int nonTake = pREV;

            int curr = max(take, nonTake);

            pREV2 = pREV;
            pREV = curr;
        }

        return max(prev, pREV);
    }
};