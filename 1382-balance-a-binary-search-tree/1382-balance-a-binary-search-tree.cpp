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
public:
    vector<TreeNode*> trees;
    int n;
    void f(TreeNode* t) {
        if (t == nullptr)
            return;
        f(t->left);
        trees.push_back(t);
        f(t->right);
    }
    TreeNode* r(int st, int en) {
        if (st > en) return nullptr;
        int mid = (st + en) / 2;
        TreeNode* newNode = trees[mid];
        newNode->left = r(st, mid - 1);
        newNode->right = r(mid + 1, en);
        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        f(root);
        n = trees.size();
        return r(0, n - 1);
    }
};