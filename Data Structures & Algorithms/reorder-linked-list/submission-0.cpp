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
    void reorderList(ListNode* head) {
        //[0, n-1, 1, n-2, 2, n-3, ...]
        //[0, 1, 2, n-3, n-2, n-1]
        // fast and slow pointers: reverse the sec part
        // [0, 1, 2, n-1, n-2, n-3]
        // reorder the list as req [0, n-1, 1, n-2, 2, n-3, ...]
        ListNode * slow = head;
        ListNode * fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow is head of se part
        // reverse this part
        ListNode * curr = slow->next;
        ListNode * prev = slow->next = nullptr;
        while (curr) {
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode * first = head;
        ListNode * second = prev;
        // reorder the list
        while (second) {
            ListNode * firstNext = first->next;
            ListNode * secondNext = second->next;
            first->next = second;
            second->next = firstNext;
            first = firstNext;
            second = secondNext;
        }
    }
};
