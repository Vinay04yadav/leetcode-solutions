// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/max-consecutive-ones/description/
// Difficulty: Easy
// Topic: Arrays

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int most_consecutive = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count > most_consecutive)
            {
                most_consecutive = count;
            }
        }

        return most_consecutive;
    }
};