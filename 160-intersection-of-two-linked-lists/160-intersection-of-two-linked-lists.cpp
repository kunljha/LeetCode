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
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        while(currA != nullptr && currB != nullptr) {
            if(currA == currB) return currA;
            
            
            currA = currA->next;
            currB = currB->next;
            
            if(currA == nullptr) currA = headB;
            else if(currB == nullptr) currB = headA;    
        }
        
        return nullptr;
    }
};