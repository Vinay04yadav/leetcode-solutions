// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty: Medium
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
    void recursiveTraversal(TreeNode *node, int level, vector<int> &result)
    {
        if (node == NULL)
        {
            return;
        }
        if (level == result.size())
        {
            result.push_back(node->val);
        }
        recursiveTraversal(node->right, level + 1, result);
        recursiveTraversal(node->left, level + 1, result);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        recursiveTraversal(root, 0, result);
        return result;
    }
};