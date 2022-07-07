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
        int d = 0;
        bool ans =  rec(root,d);
        return ans;
    }
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool rec(TreeNode* root,int &d){
        if(root==NULL) return true;
        int leftDistance =0;
        int rightDistance =0;
        bool isLeftBal = rec(root->left,leftDistance);
        bool isRightBal = rec(root->right,rightDistance);
        int diff = abs(leftDistance-rightDistance);
        bool isBal = diff>=0 and diff<=1;
        d = max(leftDistance,rightDistance)+1;
        return isBal and isLeftBal and isRightBal;
    }
};