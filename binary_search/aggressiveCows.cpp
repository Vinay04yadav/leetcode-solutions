// Problem: Aggressive cows
// Link: -
// Difficulty: Medium
// Topic: Binary Search

bool canWePlace(vector<int> &stalls, int distance, int cows)
{
    int cntCows = 1;
    int n = stalls.size();
    int last = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - last) >= distance)
        {
            cntCows++;
            last = stalls[i];
        }

        if (cntCows >= cows)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canWePlace(stalls, mid, k) == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans; // or we can return high as well because of polarity thing, high will anyways point to max possible answer at the end of BS
}