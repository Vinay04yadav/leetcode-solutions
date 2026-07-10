// Problem: Find first and last position of element in sorted array
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Difficulty: Medium
// Topic: Binary Search

// brute:

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = -1;
        int last = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                {
                    first = i;
                }
                last = i;
            }
        }
        return {first, last};
    }
};

// optimal ( with lower and upper bound) -> if you look at the problem, first occ = lb index and last occ = ub index - 1 with edgecases like lb == n || arr[lb] != target return {-1, -1}

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int lb = n;
        int ub = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                high = mid - 1;
                lb = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        low = 0;
        high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                high = mid - 1;
                ub = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (lb == n || nums[lb] != target)
        {
            return {-1, -1};
        }
        else
        {
            return {lb, ub - 1};
        }
    }
};

// specifally using binary search:

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first = -1;
        int last = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
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

        if (first == -1)
            return {-1, -1};

        low = 0;
        high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
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

        return {first, last};
    }
};
