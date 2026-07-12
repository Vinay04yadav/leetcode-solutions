// Problem: Split array largest sum
// Link: https://leetcode.com/problems/split-array-largest-sum/description/
// Difficulty: Hard
// Topic: Binary Search

class Solution
{
public:
    int countSubArrays(vector<int> &array, int maxSum, int n)
    {
        int subArrays = 1;
        int currentSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (currentSum + array[i] <= maxSum)
            {
                currentSum += array[i];
            }
            else
            {
                subArrays++;
                currentSum = array[i];
            }
        }

        return subArrays;
    }

    int splitArray(vector<int> &nums, int k)
    {

        int n = nums.size();

        if (k > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int subArrays = countSubArrays(nums, mid, n);

            if (subArrays > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};