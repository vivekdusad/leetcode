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
    TreeNode* prev;
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL) return;
        st.push(root);
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            if(curr->right != NULL){
                st.push(curr->right);
            }
            if(curr->left != NULL){
                st.push(curr->left);
            }
            
             if (!st.empty()) {
                curr -> right = st.top();
            }
            curr->left = NULL;
        }
    }
};