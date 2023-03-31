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
    // submission for daily challenge
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(ListNode* listhead : lists) {
            if(listhead) pq.push({ listhead->val, listhead });
        }
        
        if(pq.empty()) return NULL;
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while(not pq.empty()) {
            int minVal = pq.top().first;
            ListNode* minNode = pq.top().second;
            pq.pop();
            
            if(minNode->next)
                pq.push({ minNode->next->val, minNode->next });
            
            tail->next = minNode;
            tail = minNode;
        }
        
        return dummy->next;     
    }
};