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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int low = m-1;
        int top = 0;
        int left =0;
        int right = n-1;
        int dir =0;
        while(head != NULL){            
           if(dir==0){
               for(int i=left;i<=right and head != NULL;i++){
                   matrix[top][i]=head->val;
                   head = head->next;
               }
               top++;
           }
            if(dir==1){
                for(int i=top;i<=low and head != NULL;i++){
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left and head != NULL;i--){
                    matrix[low][i] = head->val;
                    head = head->next;
                }
                low--;
            }
            if(dir==3){
                for(int i=low;i>=top and head != NULL;i--){
                    matrix[i][left] = head->val;
                    head= head->next;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return matrix;
    }
};