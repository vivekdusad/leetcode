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

class NodeValue{
public:
    NodeValue(int maxValue,int minValue,int sum,bool isBst){
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->sum = sum;
        this->isBst = isBst;
    }
    int maxValue;
    int minValue;
    int sum;
    bool isBst;
};


class Solution {
private:
    NodeValue maxSumBstHelper(TreeNode* root,int &maxSum){
        if(root==NULL) return NodeValue(INT_MIN,INT_MAX,0,true); 
        
        auto leftNodeValue = maxSumBstHelper(root->left,maxSum);
        auto rightNodeValue = maxSumBstHelper(root->right,maxSum);
        auto isCurrBst = (root->val > leftNodeValue.maxValue) and (root->val < rightNodeValue.minValue);
        
        if(isCurrBst and leftNodeValue.isBst and rightNodeValue.isBst){
            maxSum = max(maxSum,root->val+leftNodeValue.sum+rightNodeValue.sum);
            int minValue = min(root->val,min(rightNodeValue.minValue,leftNodeValue.minValue));
            int maxValue  = max(root->val,max(rightNodeValue.maxValue,leftNodeValue.maxValue));
            int sum = root->val+leftNodeValue.sum+rightNodeValue.sum;
            return NodeValue(maxValue,minValue,sum,true);
        }
        
        return NodeValue(INT_MAX,INT_MIN,max(leftNodeValue.sum,rightNodeValue.sum),false);
    }
public:
    int maxSumBST(TreeNode* root) {
        if(root==NULL) return 0;
        int maxSum = 0;
        NodeValue nodeValue = maxSumBstHelper(root,maxSum);
        return maxSum;
    }
}; 







/*
    int maxSumBstUtil(TreeNode* root,int &minValue,int &maxValue,int &maxAns){
        // Exception Handling
        if(root==NULL) return 0;
        auto value = root->val;
        bool isCurrTreeBst = (value>minValue) and (value<maxValue);
        int isLeftTreeBst = maxSumBstUtil(root->left,minValue,value,maxAns);
        int isRightTreeBst = maxSumBstUtil(root->right,value,maxValue,maxAns);
        cout<<root->val<<" "<<isCurrTreeBst<<" "<<isLeftTreeBst<<" "<<isRightTreeBst<<endl;
        if(isCurrTreeBst and (isLeftTreeBst>=0) and (isRightTreeBst>=0)){
            int maxSum = max(isLeftTreeBst,max(isRightTreeBst,isLeftTreeBst+isRightTreeBst+root->val));
            maxAns = max(maxAns,maxSum);
            return maxSum;
        }else if((isLeftTreeBst>=0) and (isRightTreeBst>=0)){
            return 
        }
            return -1;
    }



*/


















