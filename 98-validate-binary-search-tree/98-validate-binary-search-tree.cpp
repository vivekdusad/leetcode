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
using ll = long long;
class Solution {
public:
    bool isInRange(TreeNode* root,long max,long min){
        if(root==NULL) return true;
        
        bool isLeftBst = isInRange(root->left,root->val,min);
        bool isRightBst = isInRange(root->right,max,root->val);
        bool isRootInRange = (root->val>min) and (root->val<max);
        return isLeftBst and isRightBst and isRootInRange;
    }
    bool isValidBST(TreeNode* root) {
        
        return isInRange(root,LONG_MAX,LONG_MIN);
    }
};