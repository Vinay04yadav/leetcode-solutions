// Problem: Maximum subarray with largest sum
// Link: https://leetcode.com/problems/maximum-subarray/description/
// Difficulty: Medium
// Topic: Arrays

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            if (sum > maxi)
            {
                maxi = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxi;
    }
};