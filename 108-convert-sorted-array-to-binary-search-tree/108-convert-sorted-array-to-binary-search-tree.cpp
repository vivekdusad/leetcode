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
    TreeNode* buildBst(vector<int>& nums,int start,int end){
        if(nums.size()==0 or start>end) return NULL;
        int mid = (start+end)/2;
        auto rightChild = buildBst(nums,mid+1,end);
        auto leftChild = buildBst(nums,start,mid-1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->right = rightChild;
        root->left = leftChild;
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBst(nums,0,nums.size()-1);
    }
};