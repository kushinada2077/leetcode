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
        unordered_map<int, ListNode*> map;
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = head;
        int sum = 0;
        map[0] = dummyHead;

        while (cur) {
            sum += cur->val;

            if (map.find(sum) != map.end()) {
                ListNode* preFrom = map[sum];
                ListNode* from = preFrom->next;
                preFrom->next = cur->next;
                int tmpSum = sum;

                while (from != cur) {
                    tmpSum += from->val;
                    from = from->next;
                    map.erase(tmpSum);
                }
            }
            else {
                map[sum] = cur;
            }

            cur = cur->next;
        }

        return dummyHead->next;
    };
};