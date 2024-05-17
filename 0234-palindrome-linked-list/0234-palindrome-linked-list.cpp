/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #define ll long long
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* cur = head;

        while (cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }

        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            if (nums[i] != nums[n - 1 - i]) return false;
        }

        return true;
    }
};