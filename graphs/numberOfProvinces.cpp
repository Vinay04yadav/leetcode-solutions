// Problem: Number of Provinces
// Link: https://leetcode.com/problems/number-of-provinces/description/
// Difficulty: Medium
// Topic: Graphs

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &visited)
    {
        visited[node] = 1;
        int n = isConnected.size();

        for (int j = 0; j < n; j++)
        {
            // if there is a connection and the neighbor hasn't been visited
            if (isConnected[node][j] == 1 && !visited[j])
            {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int nodes = isConnected.size();
        vector<int> visited(nodes, 0);
        int count = 0;

        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};