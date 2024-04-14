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
class Solution {
public:
    int sum = 0;
    void traverse(TreeNode* cur, char l) {
        if (!cur) return;
        if (l == 'L') sum += cur->val;
        traverse(cur->left, 'L');
        traverse(cur->right, 'R');
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root, 'r');

        return sum;
    }
};