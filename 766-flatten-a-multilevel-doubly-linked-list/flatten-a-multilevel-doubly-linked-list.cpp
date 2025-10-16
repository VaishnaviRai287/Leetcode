/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp){
            if(temp->child){
                Node* next = temp->next;
                Node* child = flatten(temp->child);
                temp->next = child;
                child->prev = temp;
                temp->child = nullptr;
                //need tail
                Node* tail = child;
                while(tail->next) tail= tail->next;
                tail->next = next;
                if(next) next->prev = tail;
            }
            temp = temp->next;
        }
        return head;
    }
};