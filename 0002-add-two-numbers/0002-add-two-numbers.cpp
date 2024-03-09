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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* head = new ListNode();
        ListNode* tail = head;
        int carry = 0;

        while (cur1 || cur2 || carry) {
            int digit1 = cur1 ? cur1->val : 0;
            int digit2 = cur2 ? cur2->val : 0;
            int sum = digit1 + digit2 + carry;

            carry = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            tail->next = newNode;
            tail = tail->next;
            cur1 = cur1 ? cur1->next : nullptr;
            cur2 = cur2 ? cur2->next : nullptr;
        } 

        return head->next;
    }
};