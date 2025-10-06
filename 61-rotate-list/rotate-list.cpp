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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        ListNode* temp = head;
        int length = 1;
        while(temp->next){
            length++;
            temp=temp->next;
        }
        k=k%length;
        if(k==0) return head;
        temp->next = head;
        int cnt = length-k;
        ListNode* new_tail = head;
        for (int i = 0; i < cnt - 1; i++) {
            new_tail = new_tail->next;
        }
        ListNode* new_head = new_tail->next; 
        new_tail->next = nullptr; 
        return new_head;
    }
};