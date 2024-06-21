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
    int ans = 0;
    vector<int> cnt = vector<int>(10, 0);
    bool isPal() {
        int odd = 0;
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] % 2) odd++;
        }
        return odd < 2;
    }
    void sol(TreeNode* cur) {
        cnt[cur->val]++;
        if (cur->left) sol(cur->left);
        if (cur->right) sol(cur->right);
        if (!cur->left && !cur->right && isPal()) ans++;  
        cnt[cur->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        sol(root);
        return ans;
    }
};