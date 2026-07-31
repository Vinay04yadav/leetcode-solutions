// Problem: Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/description/
// Difficulty: Easy
// Topic: Stacks and Queues

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ngeMap;
        stack<int> st;

        // traverse nums2 from right to left to find NGE for each element
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            // if stack is empty, no greater element exists (-1)
            // otherwise, top of the stack is the next greater element
            ngeMap[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        // build the result for nums1 using the map
        vector<int> result;
        for (int num : nums1)
        {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};