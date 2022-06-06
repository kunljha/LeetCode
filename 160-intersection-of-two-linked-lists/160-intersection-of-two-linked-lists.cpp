/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       unordered_set<ListNode*> hash;
        
        ListNode* temp = headA;
       
        while(temp != NULL) {
            hash.insert(temp);
            temp = temp->next;
        }
        
        temp = headB;
        
        while(temp != NULL) {
            if(hash.find(temp) != hash.end()) return temp;
            
            hash.insert(temp);
            temp = temp->next;
        }
        
        return NULL;
    }
};