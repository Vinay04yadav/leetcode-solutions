// Problem: Reverse Words in String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/description/
// Difficulty: Medium
// Topic: Strings

class Solution
{
public:
    string reverseWords(string s)
    {
        int length = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < length; i++)
        {
            string word = "";

            while (i < length && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (!word.empty())
            {
                if (ans.empty())
                {
                    ans = word;
                }
                else
                {
                    ans += " " + word;
                }
            }
        }

        return ans;
    }
};