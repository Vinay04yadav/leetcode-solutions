// Problem: reverse integer
// Link: https://leetcode.com/problems/reverse-integer/description/
// Difficulty: Medium
// Topic: Basic Math

class Solution
{
public:
    int reverse(int x)
    {
        int revNum = 0;
        while (x != 0)
        {
            int lastDigit = x % 10;
            x = x / 10;

            if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && lastDigit > 7))
                return 0;

            if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && lastDigit < -8))
                return 0;

            revNum = (revNum * 10) + lastDigit;
        }
        return revNum;
    }
};