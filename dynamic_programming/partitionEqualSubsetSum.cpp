// Problem: Partition Equal Subset Sum
// Link: https://leetcode.com/problems/partition-equal-subset-sum/description/
// Difficulty: Medium
// Topic: Dynamic Programming

// Memoization

class Solution
{
public:
    bool partition(int ind, vector<int> &nums, vector<vector<int>> &dp, int sum)
    {
        if (sum == 0)
            return true;
        if (ind == 0)
            return nums[0] == sum;

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        bool notTake = partition(ind - 1, nums, dp, sum);
        bool take = false;
        if (nums[ind] <= sum)
        {
            take = partition(ind - 1, nums, dp, sum - nums[ind]);
        }

        return dp[ind][sum] = notTake || take;
    }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return partition(n - 1, nums, dp, target);
    }
};

// Tabulation:
