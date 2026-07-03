// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Difficulty: Easy
// Topic: Arrays

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        int index = 0;
        for (auto it : st)
        {
            nums[index] = it;
            index++;
        }
        return index;
    }
};