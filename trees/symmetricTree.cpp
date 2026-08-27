// Problem: Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree/
// Difficulty: Easy
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
    bool symmetricfunc(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
        {
            return left == right;
        }

        if (left->val != right->val)
        {
            return false;
        }

        return symmetricfunc(left->left, right->right) && symmetricfunc(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        return root == NULL || symmetricfunc(root->left, root->right);
    }
};