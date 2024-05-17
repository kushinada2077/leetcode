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
        ll num = 0;
        ListNode* cur = head;

        while (cur) {
            num *= 10;
            num += cur->val;
            cur = cur->next;
        }

        ll comp = num, tmp = 0;
        while (num) {
            tmp *= 10;
            tmp += num % 10;
            num /= 10; 
        }

        return comp == tmp;
    }
};