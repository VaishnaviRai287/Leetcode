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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int,ListNode*>, 
            vector<pair<int,ListNode*>>,
            greater<pair<int,ListNode*>>
            > pq;

        for(ListNode* head: lists){
            if(head){
                pq.push({head->val, head});
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()){
            pair<int, ListNode*> top = pq.top();
            pq.pop();
            ListNode* smallest = top.second;
            temp->next = smallest;
            temp = temp->next;
            if(smallest->next){
                ListNode* next = smallest->next;
                pq.push({next->val, next});
            }
        }

        ListNode* result = dummy->next;
        delete(dummy);
        return result;

    }
};