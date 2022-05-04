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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        
        ListNode *curr = head;
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        int start = 0, end = v.size() - 1;
        while(start <= end) {
           if(v[start] == v[end]){
               start++; end--;
           }
           else return false;  
        }
        return true;
    }
};