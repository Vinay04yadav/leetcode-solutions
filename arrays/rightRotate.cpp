// Problem: Rotate Array
// Link: https://leetcode.com/problems/rotate-array/description/
// Difficulty: Easy
// Topic: Arrays

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        // // store k elements in temp array
        // vector<int> temp;
        // temp.reserve(k); // reserving only k spaces

        // for(int i = n - k; i < n; i++){
        //     temp.push_back(nums[i]);
        // }

        // // put the remaining elements at their place.
        // for(int i = n - k - 1; i >= 0; i--){
        //     nums[i + k] = nums[i];
        // }

        // // put temp into nums
        // int j = 0;
        // for(int i = 0; i < k; i++){
        //     nums[i] = temp[j];
        //     j++;
        // }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};