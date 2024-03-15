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
        ListNode* from = head;
        ListNode* to = head;
        ListNode* preFrom;
        ListNode* myHead = head;
        int sum = 0;

        while (from) {
            if (!to) {
                preFrom = from;
                from = from->next;
                to = from;
                sum = 0;
                continue;
            }

            sum += to->val;

            if (!sum) {
                if (myHead == from) {
                    from = to = myHead = to->next;
                    continue;
                }
                if (to->next) {
                    from->val = to->next->val;
                    from->next = to->next->next; 
                    to = from;
                    continue;
                }      
                else {
                    preFrom->next = nullptr;
                    break;
                }
            }

            to = to->next;
        }

        return myHead;
    }
};