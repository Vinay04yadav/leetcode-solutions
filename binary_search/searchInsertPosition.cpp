// Problem: Search Insert Position
// Link: https://leetcode.com/problems/search-insert-position/description/
// Difficulty: Easy
// Topic: Binary Search

#include <bits/stdc++.h>
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        long long lb = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                lb = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return lb;
    }
};