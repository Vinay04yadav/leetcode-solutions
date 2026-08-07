// Problem: Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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
    void helperRecursive(TreeNode *node, vector<int> &ans)
    {
        if (node == NULL)
        {
            return;
        }
        helperRecursive(node->left, ans);
        ans.push_back(node->val);
        helperRecursive(node->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        helperRecursive(root, ans);
        return ans;
    }
};