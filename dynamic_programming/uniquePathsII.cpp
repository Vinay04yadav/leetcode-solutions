// Problem: Unique Paths ii
// Link: https://leetcode.com/problems/unique-paths-ii/description/
// Difficulty: Medium
// Topic: Dynamic Programming

// Memoization

class Solution
{
public:
    int paths(int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (m >= 0 && n >= 0 && obstacleGrid[m][n] == 1)
        {
            return 0;
        }
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

        int up = paths(m - 1, n, obstacleGrid, dp);
        int left = paths(m, n - 1, obstacleGrid, dp);

        return up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return paths(m - 1, n - 1, obstacleGrid, dp);
    }
};

// tabulation

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    cur[j] = 0;
                else if (i == 0 && j == 0)
                    cur[j] = 1;
                else
                {
                    int up = 0, left = 0;
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