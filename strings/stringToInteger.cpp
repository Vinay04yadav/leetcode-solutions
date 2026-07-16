// Problem: String to Integer (atoi)
// Link: https://leetcode.com/problems/string-to-integer-atoi/description/
// Difficulty: Medium
// Topic: Strings

class Solution
{
public:
    int myAtoi(std::string s)
    {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long result = 0;

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            result = result * 10 + digit;

            if (sign == 1 && result > INT_MAX)
            {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN)
            {
                return INT_MIN;
            }

            i++;
        }

        return result * sign;
    }
};