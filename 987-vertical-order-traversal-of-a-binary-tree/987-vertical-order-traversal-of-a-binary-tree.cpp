class Solution {
public:    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>> mp;//displacment,level,Node->val
        queue<pair<TreeNode*,pair<int,int>>> q;//Node,displacment,level
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int dis = p.second.first;
            int level = p.second.second;
            mp[dis][level].insert(curr->val);
            if(curr->left != NULL){
                q.push(make_pair(curr->left,make_pair(dis-1,level+1)));
            }
            if(curr->right != NULL){
                q.push(make_pair(curr->right,make_pair(dis+1,level+1)));
            }
        }
        for(auto it:mp){
            vector<int> curr;
            for(auto i:it.second){
                curr.insert(curr.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(curr);
        }
        return ans;
    }
};