// Problem: Search A 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Difficulty: Medium
// Topic: Binary Search

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows * cols - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (matrix[mid / cols][mid % cols] == target)
            {
                return true;
            }
            else if (matrix[mid / cols][mid % cols] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};