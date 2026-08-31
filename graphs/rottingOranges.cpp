// Problem: Rotting Oranges
// Link: https://leetcode.com/problems/rotting-oranges/description/
// Difficulty: Medium
// Topic: Graphs

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // The format of the queue is : {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;

        int visited[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
            }
        }

        int time = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t, time);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int neighbourRow = r + drow[i];
                int neighbourCol = c + dcol[i];
                if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && visited[neighbourRow][neighbourCol] != 2 && grid[neighbourRow][neighbourCol] == 1)
                {
                    q.push({{neighbourRow, neighbourCol}, t + 1});
                    visited[neighbourRow][neighbourCol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};