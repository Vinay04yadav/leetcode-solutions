// Problem: Minimum Number of Days to Make M Bouquets
// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Difficulty: Medium
// Topic: Binary Search

class Solution
{
public:
    // helper to find the maximum bloom day
    int getMax(vector<int> &n)
    {
        int maxVal = n[0];
        for (int i = 1; i < n.size(); i++)
        {
            if (n[i] > maxVal)
            {
                maxVal = n[i];
            }
        }
        return maxVal;
    }

    // min bloom day
    int getMin(vector<int> &n)
    {
        int minVal = n[0];
        for (int i = 1; i < n.size(); i++)
        {
            if (n[i] < minVal)
            {
                minVal = n[i];
            }
        }
        return minVal;
    }

    // counts how many bouquets of size k can be made by 'day'
    int howManyCanBloom(vector<int> &arr, int day, int k)
    {
        int bouquets = 0;
        int consecutiveFlowers = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= day)
            {
                consecutiveFlowers++;
                if (consecutiveFlowers == k)
                {
                    bouquets++;
                    consecutiveFlowers = 0; // Reset for the next bouquet
                }
            }
            else
            {
                consecutiveFlowers = 0; // Streak broken
            }
        }
        return bouquets;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        int low = getMin(bloomDay);
        int high = getMax(bloomDay);
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // if we can make at least m bouquets, try to find a smaller day
            if (howManyCanBloom(bloomDay, mid, k) >= m)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};