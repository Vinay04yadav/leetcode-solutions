// Problem: Partition Array Into Two Arrays To Minimize Sum Difference
// Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
// Difficulty: Hard
// Topic: Dynamic Programming

class Solution
{
public:
    void dfs(const vector<int> &arr, int i, int count, int path, vector<vector<int>> &sums)
    {
        if (i == arr.size())
        {
            sums[count].push_back(path);
            return;
        }
        // Pick current element
        dfs(arr, i + 1, count + 1, path + arr[i], sums);
        // Skip current element
        dfs(arr, i + 1, count, path, sums);
    }

    int minimumDifference(vector<int> &nums)
    {
        int totalSize = nums.size();
        int n = totalSize / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int goal = totalSum / 2;

        vector<int> lNums(nums.begin(), nums.begin() + n);
        vector<int> rNums(nums.begin() + n, nums.end());

        vector<vector<int>> lSums(n + 1);
        vector<vector<int>> rSums(n + 1);

        dfs(lNums, 0, 0, 0, lSums);
        dfs(rNums, 0, 0, 0, rSums);

        int ans = INT_MAX;

        // We need to pick lCount elements from the left half
        // and n - lCount elements from the right half.
        for (int lCount = 0; lCount <= n; ++lCount)
        {
            auto &l = lSums[lCount];
            auto &r = rSums[n - lCount];
            sort(r.begin(), r.end());

            for (const int lSum : l)
            {
                int target = goal - lSum;
                auto it = lower_bound(r.begin(), r.end(), target);

                if (it != r.end())
                {
                    int sumPartOne = lSum + *it;
                    int sumPartTwo = totalSum - sumPartOne;
                    ans = min(ans, abs(sumPartOne - sumPartTwo));
                }
                if (it != r.begin())
                {
                    auto prevIt = prev(it);
                    int sumPartOne = lSum + *prevIt;
                    int sumPartTwo = totalSum - sumPartOne;
                    ans = min(ans, abs(sumPartOne - sumPartTwo));
                }
            }
        }

        return ans;
    }
};