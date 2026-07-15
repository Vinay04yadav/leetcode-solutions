// Problem: Permutation in String
// Link: https://leetcode.com/problems/permutation-in-string/description/
// Difficulty: Medium
// Topic: Strings

#include <string>
#include <vector>

class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        int length1 = s1.length();
        int length2 = s2.length();

        if (length1 > length2)
        {
            return false;
        }

        vector<int> s1_frequency(26, 0);
        vector<int> s2_frequency(26, 0);

        for (int i = 0; i < length1; ++i)
        {
            s1_frequency[s1[i] - 'a']++;
            s2_frequency[s2[i] - 'a']++;
        }

        if (s1_frequency == s2_frequency)
        {
            return true;
        }

        for (int i = length1; i < length2; ++i)
        {
            s2_frequency[s2[i] - 'a']++;

            s2_frequency[s2[i - length1] - 'a']--;

            if (s1_frequency == s2_frequency)
            {
                return true;
            }
        }

        return false;
    }
};