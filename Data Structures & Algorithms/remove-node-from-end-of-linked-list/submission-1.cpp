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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        // calc number of nodes size
        int size = 1;
        ListNode * dummy = head;
        while (dummy->next) {
            size++;
            dummy = dummy->next;
        }
        cout << "size: " << size << endl;
        // k th node to delete has idx = size - n 

        int idx = size - n;
        cout << "idx: " << idx << endl;
        ListNode res(-1, head);
        ListNode * prev = &res;
        ListNode * curr = head;
        ListNode * next = nullptr;
        if (curr->next) {
            next = curr->next;
        }
        int i = 0; // <- curr idx

        while (i < idx) {
            i++;
            prev = curr;
            curr = curr->next;
            if (curr->next) {
                next = curr->next;
            } else {
                next = nullptr;
            }
        }
        prev->next = next;

        // prev -> node -> next 
        // after deletion prev -> next 
        return res.next;
    }
};
