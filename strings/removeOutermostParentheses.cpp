// Problem: Remove Outermost Parentheses
// Link: https://leetcode.com/problems/remove-outermost-parentheses/description/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int opened = 0;
        string ans = "";
        int n = s.length();
        int i = 0;

        while (i < n)
        {
            if (s[i] == '(')
            {
                if (opened == 0)
                {
                    opened++;
                    i++;
                    continue;
                }
                else
                {
                    ans += s[i];
                    opened++;
                    i++;
                }
            }
            else if (s[i] == ')')
            {
                opened--;
                if (opened == 0)
                {
                    i++;
                    continue;
                }
                else
                {
                    ans += s[i];
                    i++;
                }
            }
        }

        return ans;
    }
};