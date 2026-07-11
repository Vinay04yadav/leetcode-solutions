// Problem: Find Least Capacity to Ship Packages Within D Days
// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Difficulty: Medium
// Topic: Binary Search

class Solution
{
public:
    int daysTaken(vector<int> &weights, int capacity)
    {
        int days = 1;
        int load = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++)
        {
            if (weights[i] + load > capacity)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int numberOfDays = daysTaken(weights, mid);
            if (numberOfDays <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};