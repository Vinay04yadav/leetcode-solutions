// Problem: Isomorphic Strings
// Link: https://leetcode.com/problems/valid-anagram/description/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();
        if (n != t.length())
            return false;
        int map[26] = {0};

        for (int i = 0; i < n; i++)
        {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (map[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};