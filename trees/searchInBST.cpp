// Problem: Search In A Binary Search Tree
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/
// Difficulty: Easy
// Topic: Trees

// using recursion (time : O(N), space : O(N))

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
    TreeNode *search(TreeNode *node, int value)
    {
        if (node == NULL || node->val == value)
        {
            return node;
        }
        else if (value < node->val)
        {
            return search(node->left, value);
        }
        else
        {
            return search(node->right, value);
        }
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        return search(root, val);
    }
};

// using iterative approach (time : O(N), space : O(1) -> not taking auxillary space)

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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *current = root;

        while (current != nullptr && current->val != val)
        {
            if (val < current->val)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        return current;
    }
};