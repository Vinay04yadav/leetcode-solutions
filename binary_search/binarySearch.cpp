// Problem: Binary Search
// Link: https://leetcode.com/problems/binary-search/description/
// Difficulty: Easy
// Topic: Binary Search

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};

// recursive solution:

int bs(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + ((high - low) / 2) if (nums[mid] == target)
    {
        return mid;
    }
    else if (target > nums[mid]) return bs(nums, mid + 1, high, target);
    else return bs(nums, low, mid - 1, target);
}

int search(vector<int> &nums, int target)
{
    return bs(nums, 0, nums.size() - 1, target);
}