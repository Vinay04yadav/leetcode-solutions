// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas/description/
// Difficulty: Medium
// Topic: Binary Search

class Solution
{
public:
    int max(vector<int> &n)
    {
        int max = n[0];
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] > max)
            {
                max = n[i];
            }
        }
        return max;
    }

    long long findhours(vector<int> &n, int middle)
    {
        long long hours = 0; // Changed to long long

        for (int i = 0; i < n.size(); i++)
        {
            // The ceiling division is correct
            hours += (long long)(n[i] + middle - 1) / middle;
        }

        return hours;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = max(piles);
        int ans;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            long long hours = findhours(piles, mid);
            if (hours > h)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};