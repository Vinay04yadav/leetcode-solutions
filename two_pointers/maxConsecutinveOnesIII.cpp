// Problem: Max Consecutive Ones III
// Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/
// Difficulty: Medium
// Topic: Linked List

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int zeroes = 0;

        while (right < n)
        {
            if (nums[right] == 0)
            {
                zeroes++;
            }
            if (zeroes > k)
            {
                if (nums[left] == 0)
                {
                    zeroes--;
                    left++;
                }
                else
                {
                    left++;
                }
            }
            if (zeroes <= k)
            {
                int len = right - left + 1;
                maxLen = max(len, maxLen);
            }
            right++;
        }
        return maxLen;
    }
};