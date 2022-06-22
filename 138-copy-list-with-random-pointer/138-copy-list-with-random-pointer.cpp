/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {       
        Node* itr1 = head;
        Node* front = head;
        Node* head2 = new Node(0);
        Node* itr2 = head2;
         //Step1 : Insert Nodes
        while(itr1 != NULL){
            front = itr1->next;
            Node* newNode = new Node(itr1->val);
            itr1->next = newNode;
            newNode->next = front;
            itr1 = front;
        }
        //Step 2 Assign the Random Pointers
        itr1 = head;
        while(itr1 != NULL){
            if(itr1->random != NULL){
                itr1->next->random = itr1->random->next;
            }
            itr1 = itr1->next->next;
        }
        //Step 3 Remove Nodes and Attach to New Link List
        front = head;
        itr1 = head;
        while(itr1 != NULL){
            front = itr1->next->next;
            itr2->next= itr1->next;
            itr1->next = front;
            itr2 = itr2->next;
            itr1 = front;
        }
        return head2->next;
    }
};