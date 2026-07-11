// Problem: Find the smallest divisor given a threshold
// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// Difficulty: Medium
// Topic: Binary Search

class Solution
{
public:
    int getMax(vector<int> &n)
    {
        int maxVal = n[0];
        for (int i = 1; i < n.size(); i++)
        {
            if (n[i] > maxVal)
            {
                maxVal = n[i];
            }
        }
        return maxVal;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = getMax(nums);
        int n = nums.size();
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum = sum + (nums[i] + mid - 1) / mid;
            }

            if (sum > threshold)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};