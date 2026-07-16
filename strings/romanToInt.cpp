// Problem: Roman To Integer
// Link: https://leetcode.com/problems/roman-to-integer/description/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanToInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int currentVal = romanToInt[s[i]];
            if (i + 1 < n && currentVal < romanToInt[s[i + 1]])
            {
                ans -= currentVal;
            }
            else
            {
                ans += currentVal;
            }
        }

        return ans;
    }
};