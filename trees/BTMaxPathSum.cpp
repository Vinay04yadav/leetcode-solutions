// Problem: Binary Tree Maximum Path Sum
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
// Difficulty: Hard
// Topic: Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int totalSum(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return 0;

        int leftSum = max(0, totalSum(root->left, sum));
        int rightSum = max(0, totalSum(root->right, sum));

        sum = max(sum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;

        totalSum(root, sum);
        return sum;
    }
};