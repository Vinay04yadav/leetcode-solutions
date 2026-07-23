// Problem: Lemonade Change
// Link: https://leetcode.com/problems/lemonade-change/description/
// Difficulty: Easy
// Topic: Greedy Algorithm

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five_dollar = 0;
        int ten_dollar = 0;

        if (bills[0] != 5)
        {
            return 0;
        }
        else
        {
            for (int bill : bills)
            {
                if (bill == 5)
                {
                    five_dollar++;
                }
                else if (bill == 10)
                {
                    if (five_dollar > 0)
                    {
                        five_dollar--;
                        ten_dollar++;
                    }
                }
                else
                {
                    if (five_dollar > 0 && ten_dollar > 0)
                    {
                        five_dollar--;
                        ten_dollar--;
                    }
                    else if (five_dollar >= 3)
                    {
                        five_dollar = five_dollar - 3;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};