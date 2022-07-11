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
    void pushAll(TreeNode* root){
        pushAllLeftElements(root);
    }
    void pushAllLeftElements(TreeNode* root){
        auto node = root;
        for (; node != NULL; cache.push(node), node = node->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto topNode = cache.top();
        cache.pop();
        if(topNode->right != NULL){            
            pushAllLeftElements(topNode->right);
        }
        return topNode->val;
    }
    
    
    bool hasNext() {
        return !cache.empty();
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        unordered_set<int> nodes;
        BSTIterator bstItreator = BSTIterator(root);
        while(bstItreator.hasNext()){
            int nextElement = bstItreator.next();
            int tempTarget = k-nextElement;
            if(nodes.find(tempTarget) != nodes.end()){
                return true;
            }else{
                nodes.insert(nextElement);
            }
        }
        return false;
    }
};