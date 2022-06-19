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
        int sz = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            curr = curr->next;
            ++sz;
        }
        
        ListNode* temp = nullptr;
        if(sz == n) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        curr = head;
        for(int i = 2; i <= sz-n; i++) 
            curr = curr->next;
        
        temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return head;
    }
};