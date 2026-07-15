// Problem: Remove all Occurences of a Substring
// Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
// Difficulty: Medium
// Topic: Strings

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.length() > 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};