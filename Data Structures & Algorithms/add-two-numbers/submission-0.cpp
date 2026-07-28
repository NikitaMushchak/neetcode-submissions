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
        ListNode res(-1, nullptr);
        // l1 = [1,2,3], l2 = [4,5,6]
        // out = [5,7,9]: 321 + 654 = 975.
        ListNode * prev = &res;
        bool add = false;
        
        while(l1 || l2 || add) {
            int digit = 0;
            if (l1) {
                digit += l1->val;
            }
            if (l2) {
                digit += l2->val;
            }

            if (add) {
                digit++;
                add = false;
            }
            if (digit > 9) {
                add = true;
            }
            ListNode * node = new ListNode(digit % 10);
            prev->next = node;
            prev = node;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        return res.next;
    }
};
