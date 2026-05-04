// Problem: Container with most water
// Link: https://leetcode.com/problems/container-with-most-water/description/
// Difficulty: Medium
// Topic: Two pointers

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right)
        {
            int h = min(height[left], height[right]);

            int area = h * (right - left);

            maxArea = max(maxArea, area);

            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return maxArea;
    }
};