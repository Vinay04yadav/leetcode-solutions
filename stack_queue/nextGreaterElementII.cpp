// Problem: Next Greater Element II
// Link: https://leetcode.com/problems/next-greater-element-ii/description/
// Difficulty: Medium
// Topic: Stacks and Queues

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        int loopCounter = 2 * n - 1;

        for (int i = loopCounter; i >= 0; i--)
        {
            while (!st.empty() && nums[i % n] >= st.top())
            {
                st.pop();
            }

            if (i < n)
            {
                nge[i] = st.empty() ? -1 : st.top();
            }

            st.push(nums[i % n]);
        }
        return nge;
    }
};