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
    bool isBalanced(TreeNode* root) {
        return rec(root);
    }
    bool rec(TreeNode* root){
        if(root==NULL) return true;
        int diff = abs(maxDepth(root->left)-maxDepth(root->right));
        bool isBal = diff>=0 and diff<=1;
        bool isBalLeft = rec(root->left);
        bool isBalRight = rec(root->right);
        return isBal and isBalRight and isBalLeft;
    }
};