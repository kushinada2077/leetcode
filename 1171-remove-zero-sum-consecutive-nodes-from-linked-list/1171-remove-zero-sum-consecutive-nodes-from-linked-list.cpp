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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* from = dummyHead;
        ListNode* to = head;
        int sum = 0;

        while (from->next) {
            if (!to) {
                from = from->next;
                to = from->next;
                sum = 0;
                continue;
            }

            sum += to->val;

            if (!sum) {
                from->next = to->next;
                to = from->next;
                continue;
            }

            to = to->next;
        }

        return dummyHead->next;
    }
};