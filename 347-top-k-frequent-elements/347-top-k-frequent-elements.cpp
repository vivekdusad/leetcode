class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ms;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]]++;
            }else{
                mp[nums[i]] =1;
            }
        }
        for(auto itr:mp){
            pair<int,int> p;
            p.first = itr.second;
            p.second = itr.first;
            ms.push(p);
            if(ms.size()>k){
                ms.pop();
            }
        }
        
        while(!ms.empty()){
            pair<int,int> ps = ms.top();
           // cout<<ps.second;
            ans.push_back(ps.second);
            ms.pop();
        }
        
        return ans;
    }
};