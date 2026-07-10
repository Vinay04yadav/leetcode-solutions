// Problem: Single Element in a Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// Difficulty: Medium
// Topic: Binary Search

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 1;
        int high = n - 2;

        if (n == 1)
        {
            return nums[0];
        }
        if (nums[0] != nums[1])
        {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2])
        {
            return nums[n - 1];
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            // 01,23,4,56,78 -> indices as per pairs
            // I am in left
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            {
                low = mid + 1;
            }
            // I am in right
            else
            {
                high = high - 1;
            }
        }
        return -1;
    }
};