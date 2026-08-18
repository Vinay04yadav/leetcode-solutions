// Problem: Minimum Path Sum
// Link: https://leetcode.com/problems/minimum-path-sum/description/
// Difficulty: Medium
// Topic: Dynamic Programming

// Memoization

class Solution
{
public:
    int minPath(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
        {
            return grid[0][0];
        }

        if (m < 0 || n < 0)
        {
            return 1e9;
        }

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = grid[m][n] + minPath(m - 1, n, grid, dp);
        int left = grid[m][n] + minPath(m, n - 1, grid, dp);

        return dp[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return minPath(m - 1, n - 1, grid, dp);
    }
};

// tabulation

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                }
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space Optimization

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int> (n, 0));
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[j] = grid[0][0];
                }
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if (i > 0)
                        up = grid[i][j] + prev[j];
                    if (j > 0)
                        left = grid[i][j] + cur[j - 1];

                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};