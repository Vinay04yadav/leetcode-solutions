// Problem: Largest Odd Number in String
// Link: https://leetcode.com/problems/largest-odd-number-in-string/description/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};