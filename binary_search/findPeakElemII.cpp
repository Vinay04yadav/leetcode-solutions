// Problem: Find a peak element II ( in 2D array )
// Link: https://leetcode.com/problems/find-a-peak-element-ii/description/
// Difficulty: Medium
// Topic: Binary Search

class Solution
{
public:
    int getMaxIndex(vector<vector<int>> &matrix, int rows, int col)
    {
        int maxElement = INT_MIN;
        int maxIndex = -1;

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][col] > maxElement)
            {
                maxElement = matrix[i][col];
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int low = 0;
        int high = mat[0].size() - 1;

        int rows = mat.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int maxElemRow = getMaxIndex(mat, rows, mid);

            // using if-else block here with cause the scope issue, left or right won't be accessible outside the scope of if-else block
            int left = (mid > 0) ? mat[maxElemRow][mid - 1] : -1;
            int right = (mid < mat[0].size() - 1) ? mat[maxElemRow][mid + 1] : -1;

            if (mat[maxElemRow][mid] > left && mat[maxElemRow][mid] > right)
            {
                return {maxElemRow, mid};
            }
            else if (mat[maxElemRow][mid] > left && mat[maxElemRow][mid] <= right)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};