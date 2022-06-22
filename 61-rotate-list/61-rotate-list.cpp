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
    // void rotateNodes(ListNode* head,int k){
    //     ListNode* dummy = new ListNode();
    //     prev = dummy;
    //     ListNode* prev = dummy, *curr = dummy, *nex = dummy;
    //     curr = prev->next;
    //     nex = curr->next;
    //     for(int 1;i<k;i++){
    //         curr->next = nex->next;
    //         nex->next = prev->next;
    //         prev->next = nex;
    //         nex = curr->next;
    //     }
    // }
    // ListNode* reverseLinkList(ListNode* head){
    //     ListNode* dummy = NULL;
    //     ListNode* temp = head;
    //     while(temp != NULL){
    //         temp = head->next;
    //         head->next = dummy;
    //         dummy = head;
    //         head = temp;
    //     }
    //     return dummy;
    // }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        if(k==0) return head;
        int length=0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            length++;
        }
        if(k>=length){
             k = k%length;
        }        
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            //here temp will point to last node
            temp->next = head;
            //circular link is done
            ListNode * nt = head;
            for(int i=0;i<length-k-1;i++){
                nt = nt->next;
            }
            temp = nt->next;
            nt->next = NULL;
            return temp;
        
    }
};