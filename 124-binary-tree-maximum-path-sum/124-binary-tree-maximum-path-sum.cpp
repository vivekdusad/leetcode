/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_path_sum_impl(TreeNode* root,int &max_ans){
        //if we reach the end of the tree we return 0
        if(root==NULL) return 0;
        // if(root->left==NULL and root->right==NULL) return root->val;
        //checking the maximum path in the left sub treee
        int l1 = max(0,max_path_sum_impl(root->left,max_ans));
        //also checking the maximum path sum in the right sub tree
        int r1 = max(0,max_path_sum_impl(root->right,max_ans));
        //result of including the root 
        max_ans = max(max_ans,r1+l1+root->val);
        //either we can return the total sum or root->val;
        int res =  root->val+max(r1,l1);
        // cout<<root->val<<" l1->"<<l1<<" r1-> "<<r1<<endl;
        return res;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int max_ans = INT_MIN;
        int ans =max_path_sum_impl(root,max_ans);
        return max(ans,max_ans);
        
    }
};