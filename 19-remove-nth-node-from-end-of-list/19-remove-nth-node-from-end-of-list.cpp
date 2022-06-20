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
    ListNode* removeNthFromEnd(ListNode* head, int x) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        cout<<"Length"<<n<<endl;
        temp = head;        
        if(n==x) return head->next;
        for(int i=0;i<n-x-1;i++){
            temp = temp->next;
        }
        
        cout<<"TEMP"<<temp->val<<endl;
        ListNode* te = temp->next;
        temp->next = te->next;
        return head;
    }
};