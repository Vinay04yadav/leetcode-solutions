// Problem: Rearrange array elements by sign (starts with positive)
// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Difficulty: Medium
// Topic: Arrays

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0;
        int negIndex = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
            else
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};