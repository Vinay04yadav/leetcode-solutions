// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Difficulty: Medium
// Topic: Linked List

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int l = 0;
        int r = 0;
        int hash[256];
        memset(hash, -1, sizeof(hash));
        int maxLen = 0;
        while (r < n)
        {
            if (hash[s[r]] != -1)
            {
                if (hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};