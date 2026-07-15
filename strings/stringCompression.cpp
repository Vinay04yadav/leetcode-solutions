// Problem: String Compression
// Link: https://leetcode.com/problems/string-compression/
// Difficulty: Medium
// Topic: Strings

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int index = 0;
        int n = chars.size();

        for (int i = 0; i < n; i++)
        {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch)
            {
                count++;
                i++;
            }

            if (count == 1)
                chars[index++] = ch;
            else
            {
                chars[index++] = ch;
                string countStr = to_string(count);
                for (char dig : countStr)
                {
                    chars[index++] = dig;
                }
            }
            i--;
        }
        return index;
    }
};