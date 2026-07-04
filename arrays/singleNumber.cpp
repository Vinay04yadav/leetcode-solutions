// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/single-number/
// Difficulty: Easy
// Topic: Arrays

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xorr = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};