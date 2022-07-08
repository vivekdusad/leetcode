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
private:
    void getPreOrder(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        getPreOrder(root->left,ans);
        getPreOrder(root->right,ans);
    }
    void getPostOrder(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;        
        getPostOrder(root->left,ans);
        getPostOrder(root->right,ans);
        ans.push_back(root->val);
    }
    bool isSymmetricUtil(TreeNode* &root1,TreeNode* &root2){
        if(root1==NULL|| root2==NULL){
            return root1==root2;
        }
        bool isLeftSymmetric = isSymmetricUtil(root1->left,root2->right);
        bool isRightSymmetric = isSymmetricUtil(root1->right,root2->left);
        return (root1->val==root2->val) and isLeftSymmetric and isRightSymmetric;
    }
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* root1 = root->left;
        TreeNode* root2 = root->right;
        return isSymmetricUtil(root1,root2);
    }
};

/*
vector<int> pre_order;
        getPreOrder(root,pre_order);
        vector<int> post_order;
        getPostOrder(root,post_order); 
        if(pre_order.size() != post_order.size()) return false;
        else{
            reverse(post_order.begin(),post_order.end());
            int n = pre_order.size();
            for(int i=0;i<n;i++){
                if(pre_order[i] != post_order[i]) return false;
            }
        }
        return true;*/