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
        if (!head) {
            return nullptr;
        }
        ListNode * prev = nullptr;
        ListNode * curr = head;
        
        // 1->2->3->4
        // c  n 
        while (curr) {
             ListNode * next = curr->next;
            //  cout << "prev: " << (!prev ? "null" : to_string(prev->val)) 
            //       << ", curr: " << curr->val << ", next: " 
            //       << (!next ? "null" : to_string(next->val)) << endl;
        //    prev curr next
            // prev <- curr next
            //         prev curr -> next
            curr->next = prev;
            // prev = curr
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
