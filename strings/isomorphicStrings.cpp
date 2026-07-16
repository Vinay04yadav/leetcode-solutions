// Problem: Isomorphic Strings
// Link: https://leetcode.com/problems/isomorphic-strings/description/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        int n = s.length();

        int mapS[256] = {0};
        int mapT[256] = {0};

        for (int i = 0; i < n; i++)
        {
            if (mapS[s[i]] != mapT[t[i]])
            {
                return false;
            }
            else
            {
                mapS[s[i]] = i + 1;
                mapT[t[i]] = i + 1;
            }
        }

        return true;
    }
};