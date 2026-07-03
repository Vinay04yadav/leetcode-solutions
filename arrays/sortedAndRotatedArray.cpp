// Problem: Check if Array Is Sorted and Rotated
// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
// Difficulty: Easy
// Topic: Arrays

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                int k = size - i;
                rotate(nums.begin(), nums.begin() + (size - k % size), nums.end());
                break;
            }
        }
        for (int i = 1; i < size; i++)
        {
            if (nums[i - 1] <= nums[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};