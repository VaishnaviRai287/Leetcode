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
        if (head == nullptr) {
            return nullptr;
        }
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        Node* tail = head;
        while(tail){
            if (tail->random != nullptr) {
                tail->next->random = tail->random->next;
            } else {
                tail->next->random = nullptr;
            }
            tail = tail->next->next;
        }
        Node* newHead = head->next;
        Node* oldCurr = head;
        Node* newCurr = newHead;

        while (oldCurr) {
            oldCurr->next = newCurr->next;
            if (newCurr->next) {
                newCurr->next = newCurr->next->next;
            } else {
                newCurr->next = nullptr;
            }
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }    
        return newHead;  
    }
};