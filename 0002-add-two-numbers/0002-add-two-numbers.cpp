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
        ListNode* ansCur = head;
        int carry = 0;

        while (true) {
            int sum = carry;

            if (cur1) {
                sum += cur1->val;
                cur1 = cur1->next;
            }
            
            if (cur2) {
                sum += cur2->val;
                cur2 = cur2->next;
            }

            if (!(sum || cur1 || cur2) && head->next) break;

            carry = sum / 10;
            sum %= 10;

            ListNode* newNode = new ListNode(sum);
            ansCur->next = newNode;
            ansCur = newNode;
        } 

        return head->next;
    }
};