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
    ListNode* reverseLinkList(ListNode* head){
        ListNode* dummy =NULL;
        ListNode* newHead= dummy;
        ListNode* temp = head;
        while(temp != NULL){
            temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL and fast->next and fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //reverse the right half        
       slow= reverseLinkList(slow->next);
        ListNode* temp = head;
        while(slow != NULL){
            if(slow->val == temp->val){
                slow = slow->next;
                temp = temp->next; 
                continue;
            }else{
                return false;
            }
            
        }
        return true;
    }
};