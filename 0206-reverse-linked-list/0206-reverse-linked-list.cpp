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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        auto cur = head;

        while (cur) {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        cur = head;
        int i = 0;
        int len = arr.size();
        
        while (cur) {
            cur->val = arr[len - 1 - i++];
            cur = cur->next;
        }

        return head;
    }
};