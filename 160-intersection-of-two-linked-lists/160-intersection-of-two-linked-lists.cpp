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
        unordered_set<ListNode*> seenNodes;
        while(headA){
            seenNodes.insert(headA);
            headA = headA->next;
        }
        
        while(headB){
            if(seenNodes.find(headB) != seenNodes.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};