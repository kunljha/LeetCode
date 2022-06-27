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
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head, *prev = NULL, *temp = NULL;
        
        while(fast != NULL && fast->next != NULL) { // finding mid point
            fast = fast->next->next;
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        } 

        slow = (fast != NULL ? slow->next : slow); 

        while(slow != NULL) {
            if(slow->val == prev->val) 
                slow = slow->next, prev = prev->next;
            else return false;
        }

        return true;
    }
};