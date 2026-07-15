// Problem: Longest Common Prefix
// Link: https://leetcode.com/problems/longest-common-prefix/description/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string ans = "";
        string first = strs[0];

        string last = strs[n - 1];

        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] == last[i])
            {
                ans += first[i];
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};