// Problem: Find a peak element II ( in 2D array )
// Link: https://leetcode.com/problems/reverse-string/
// Difficulty: Easy
// Topic: Strings

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};