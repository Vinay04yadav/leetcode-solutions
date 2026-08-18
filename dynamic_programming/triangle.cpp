// Problem: Triangle
// Link: https://leetcode.com/problems/triangle/description/
// Difficulty: Medium
// Topic: Dynamic Programming

// Memoization

class Solution
{
public:
    int mini(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            return triangle[n - 1][j];
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] + mini(i + 1, j, n, triangle, dp);
        int diagonal = triangle[i][j] + mini(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return mini(0, 0, n, triangle, dp);
    }
};

// Tabulation

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }

        return dp[0][0];
    }
};

// Space Optimization

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        // vector<vector<int>> dp(n, vector<int> (n, 0));

        vector<int> front(n);

        for (int j = 0; j < n; j++)
        {
            front[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> cur(n);
            for (int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j + 1];
                cur[j] = min(d, dg);
            }
            front = cur;
        }

        return front[0];
    }
};