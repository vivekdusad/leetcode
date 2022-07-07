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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        //there are two cases 
        /*
        
        if diameter passes from the root 
        then answer may be return maxDepth(root->left)+maxDepth(root->right);
        if not passes then 
        it may found in left  diameterOfBinaryTree(root->left);
        or in right diameterOfBinaryTree(root->right)
        
        */
        
        int ans1 = maxDepth(root->left)+maxDepth(root->right);
        int ans2 = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        return max(ans1,ans2);
    }
};