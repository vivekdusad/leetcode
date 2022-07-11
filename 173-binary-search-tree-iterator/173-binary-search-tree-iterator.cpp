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
        auto currNode = root;
        while(currNode->left != NULL){
            cache.push(currNode);
            currNode = currNode->left;
        }
        cache.push(currNode);
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */