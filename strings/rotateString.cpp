// Problem: Rotate String
// Link: https://leetcode.com/problems/rotate-string/description/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        if (s.length() != goal.length())
            return false;
        if (s == goal)
            return true;

        if ((s + s).find(goal) != string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};