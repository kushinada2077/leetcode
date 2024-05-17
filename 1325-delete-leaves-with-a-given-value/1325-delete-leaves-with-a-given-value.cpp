/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> p;

public:
    void sol(TreeNode* cur, int target) {
        if (cur->left) {
            p[cur->left] = cur;
            sol(cur->left, target);
        }
        if (cur->right) {
            p[cur->right] = cur;
            sol(cur->right, target);
        }
        if (!cur->left && !cur->right && cur->val == target) {
            if (p[cur]->left == cur)
                p[cur]->left = nullptr;
            else if (p[cur]->right == cur)
                p[cur]->right = nullptr;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* dummy = new TreeNode();
        dummy->left = root;
        p[root] = dummy;
        sol(root, target);
        return dummy->left;
    }
};