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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto l2_head = list2;
        ListNode* l2_tail = list2;
        while (l2_tail->next) {
            l2_tail = l2_tail->next;
        }

        int idx = 0;
        ListNode* l1_a = list1;

        while (idx + 1 < a) {
            l1_a = l1_a->next;
            idx++;
        }

        ListNode* l1_b = l1_a->next;

        while (idx < b) {
            l1_b = l1_b->next;
            idx++;
        }

        l1_a->next = l2_head;
        l2_tail->next = l1_b;

        return list1;
    }
};