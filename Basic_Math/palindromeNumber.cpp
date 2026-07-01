// Problem: Palindrome Number
// Link: https://leetcode.com/problems/palindrome-number/description/
// Difficulty: Easy
// Topic: Basic Math

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // int duplicate = x;
        // The approach I am trying is that if half reversed number is equal to the half remaining number -> it is a palindrome
        int revHalf = 0;
        int lastDigit;
        if (x < 0 || x % 10 == 0 && x != 0)
        {
            return 0;
        }
        while (revHalf < x)
        {
            lastDigit = x % 10;
            revHalf = (revHalf * 10) + lastDigit;
            x = x / 10;
        }

        if (revHalf == x || revHalf / 10 == x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};