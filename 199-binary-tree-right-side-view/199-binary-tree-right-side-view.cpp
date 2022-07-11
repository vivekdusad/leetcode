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
    void rightSideViewUtil(TreeNode* root,int level,vector<int> &ans,int &maxLevel){
        if(root==NULL) return;
        
        if(level>maxLevel){
            ans.push_back(root->val);
            maxLevel=level;
        }
        rightSideViewUtil(root->right,level+1,ans,maxLevel);
        rightSideViewUtil(root->left,level+1,ans,maxLevel);
        return;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nodes;
        int maxLevel = INT_MIN;
        rightSideViewUtil(root,0,nodes,maxLevel);
        return nodes;
    }
};