// Problem: Balanced Binary Tree
// Link: https://leetcode.com/problems/balanced-binary-tree/
// Difficulty: Easy
// Topic: Trees

// Brute:

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
    int findHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        if (left == -1 || right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        if (abs(lh - rh) > 1)
            return false;

        bool leftNode = isBalanced(root->left);
        bool rightNode = isBalanced(root->right);

        if (!leftNode || !rightNode)
            return false;

        return true;
    }
};

// Optimal:

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
    int findHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        if (left == -1 || right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {

        return findHeight(root) != -1;
    }
};