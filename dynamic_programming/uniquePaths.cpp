// Problem: Unique Paths
// Link: https://leetcode.com/problems/unique-paths/description/
// Difficulty: Medium
// Topic: Dynamic Programming

// Recursive Brute Force:

class Solution
{
public:
    int paths(int m, int n)
    {
        if (m == 0 && n == 0)
        {
            return 1;
        }
        if (m < 0 || n < 0)
        {
            return 0;
        }

        int up = paths(m - 1, n);
        int left = paths(m, n - 1);

        return up + left;
    }

    int uniquePaths(int m, int n)
    {
        return paths(m - 1, n - 1);
    }
};

// Memoization

class Solution
{
public:
    int paths(int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
        {
            return 1;
        }
        if (m < 0 || n < 0)
        {
            return 0;
        }

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = paths(m - 1, n, dp);
        int left = paths(m, n - 1, dp);

        return dp[m][n] = up + left;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m - 1, n - 1, dp);
    }
};

// Tabulation

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                }
                else
                {
                    int up = 0;
                    int left = 0;

                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    }

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

// space optimization

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    cur[j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = cur[j - 1];
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};