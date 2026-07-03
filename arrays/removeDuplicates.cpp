// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Difficulty: Easy
// Topic: Arrays

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] != nums[i])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};