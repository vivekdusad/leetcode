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
class BSTIterator {
private:
    stack<TreeNode*> cache;
    bool isReverse;
    void pushAll(TreeNode* root){
        if(root==NULL)return;
        auto node = root;
        for (; node != NULL;){
            if(isReverse){
                cache.push(node);
                node = node->right;
            }else{
                cache.push(node);
                node = node->left;
            }
        }
    }
    
public:
    BSTIterator(TreeNode* root,bool isReverse) {
        this->isReverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        auto topNode = cache.top();
        cache.pop();
        if(isReverse) pushAll(topNode->left);
        else pushAll(topNode->right);
        return topNode->val;
    }
    
    
    bool hasNext() {
        return !cache.empty(); 
    }
    
};
//Space Complexity: O(N+H)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        unordered_set<int> nodes;
        BSTIterator start = BSTIterator(root,false);
        BSTIterator end = BSTIterator(root,true);
        int valueAtStart = start.next();
        int valueAtEnd = end.next();
        while(valueAtStart<valueAtEnd){           
            int sum = valueAtStart + valueAtEnd;
            if(sum==k) return true;
            else if(sum<k){
                valueAtStart = start.next();
            }else{
                valueAtEnd = end.next();
            }
        }
        return false;
    }
};