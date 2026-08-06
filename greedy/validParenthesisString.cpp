// Problem: Valid Parenthesis String
// Link: https://leetcode.com/problems/valid-parenthesis-string/description/
// Difficulty: Medium
// Topic: Greedy Algorithm

// Brute Force with DP ( converted from recursion )

// Recursive:

class Solution
{
public:
    bool checkValidStringRecursion(string s, int index, int cnt)
    {
        int n = s.size();
        if (cnt < 0)
            return false;
        if (index == n)
            return cnt == 0;
        if (s[index] == '(')
        {
            return checkValidStringRecursion(s, index + 1, cnt + 1);
        }
        if (s[index] == ')')
        {
            return checkValidStringRecursion(s, index + 1, cnt - 1);
        }

        return checkValidStringRecursion(s, index + 1, cnt + 1) || checkValidStringRecursion(s, index + 1, cnt - 1) || checkValidStringRecursion(s, index + 1, cnt);
    }
    bool checkValidString(string s)
    {
        int index = 0;
        int cnt = 0;
        bool ans = checkValidStringRecursion(s, index, cnt);
        return ans;
    }
};

// DP:

class Solution
{
public:
    int memo[100][100];

    bool checkValidStringDP(string &s, int index, int cnt)
    {
        int n = s.size();
        if (cnt < 0)
            return false;
        if (index == n)
            return cnt == 0;

        if (memo[index][cnt] != -1)
        {
            return memo[index][cnt];
        }

        if (s[index] == '(')
        {
            return memo[index][cnt] = checkValidStringDP(s, index + 1, cnt + 1);
        }
        if (s[index] == ')')
        {
            return memo[index][cnt] = checkValidStringDP(s, index + 1, cnt - 1);
        }

        return memo[index][cnt] = checkValidStringDP(s, index + 1, cnt + 1) ||
                                  checkValidStringDP(s, index + 1, cnt - 1) ||
                                  checkValidStringDP(s, index + 1, cnt);
    }

    bool checkValidString(string s)
    {
        int n = s.size();
        memset(memo, -1, sizeof(memo));

        return checkValidStringDP(s, 0, 0);
    }
};

// Most Optimal:

class Solution
{
public:
    bool checkValidString(string s)
    {
        int min = 0;
        int max = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                min = min + 1;
                max = max + 1;
            }
            else if (s[i] == ')')
            {
                min = min - 1;
                max = max - 1;
            }
            else
            {
                min = min - 1;
                max = max + 1;
            }

            if (min < 0)
            {
                min = 0;
            }
            if (max < 0)
            {
                return false;
            }
        }

        return min == 0;
    }
};