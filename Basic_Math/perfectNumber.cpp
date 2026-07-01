// Problem: Perfect number
// Link: https://leetcode.com/problems/perfect-number/description/
// Difficulty: Easy
// Topic: Basic Math

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num <= 0)
        {
            return false;
        }

        int sum = 0;

        for (int i = 1; i * i < num; i++)
        {
            if (num % i == 0)
            {
                sum = sum + i + (num / i);
            }
        }
        if (sum - num == num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};