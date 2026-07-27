/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node *, Node*> saved;
        Node res(-1);
        Node * prev = &res;
        Node * curr = nullptr;
        Node * currOrig = head;
        // go throught the original list
        while (currOrig) {
            // val processing
            
            if (saved.count(currOrig)) {
                // we have the Node
                curr = saved[currOrig];
            } else { 
                // construct new Node
                int val = currOrig->val;
                Node * newNode = new Node(val);
                saved[currOrig] = newNode;
                curr = newNode;
            }
            prev->next = curr;
            // random pointer processing
            Node * random = currOrig->random;
            if (!random) {
                curr->random = nullptr;
            } else {
                int randomVal = random->val;
                if (saved.count(random)) { // found the random
                    curr->random = saved[random];
                } else {
                    Node * newRandom = new Node(randomVal);
                    saved[random] = newRandom;
                    curr->random = newRandom;
                }
            }
            prev = curr;
            curr = nullptr;
            currOrig = currOrig->next;
        }

        return res.next;
    }
};
