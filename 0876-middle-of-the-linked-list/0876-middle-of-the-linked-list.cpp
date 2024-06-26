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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int len = 0;

        while (cur) {
            len++;
            cur = cur->next;
        } 

        cur = head;
        for (int i = 0; i < len / 2; i++) {
            cur = cur->next;
        }

        return cur;
    }
};