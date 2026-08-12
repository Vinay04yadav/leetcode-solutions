// Problem: House Robber
// Link: https://leetcode.com/problems/house-robber/description/
// Difficulty: Medium
// Topic: Dynamic Programming

// completely recursive:

class Solution
{
public:
    int robHouse(vector<int> &nums, int ind)
    {
        if (ind == 0)
            return nums[ind];
        if (ind < 0)
            return 0;

        int pick = nums[ind] + robHouse(nums, ind - 2);
        int notPick = 0 + robHouse(nums, ind - 1);

        return max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        int ans = robHouse(nums, n - 1);

        return ans;
    }
};

// memoization:

class Solution
{
public:
    int robHouse(vector<int> &nums, int ind, vector<int> &dp)
    {
        if (ind == 0)
            return dp[ind] = nums[ind]; // it's fine if you return nums[ind] only here.
        if (ind < 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + robHouse(nums, ind - 2, dp);
        int notPick = 0 + robHouse(nums, ind - 1, dp);

        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        int ans = robHouse(nums, n - 1, dp);

        return ans;
    }
};

// tabulation:

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Fill the DP table iteratively
        for (int i = 2; i < n; i++)
        {
            int pick = nums[i] + dp[i - 2];
            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};

// space optimization:

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += prev2;
            }
            int nonTake = prev;

            int curr = max(take, nonTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};