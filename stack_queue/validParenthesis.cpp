// Problem: Valid Parenthesis
// Link: https://leetcode.com/problems/valid-parentheses/description/
// Difficulty: Easy
// Topic: Stacks and Queues

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (auto ch : s)
        {
            if (ch == ')')
            {
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            else if (ch == ']')
            {
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else if (ch == '}')
            {
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};