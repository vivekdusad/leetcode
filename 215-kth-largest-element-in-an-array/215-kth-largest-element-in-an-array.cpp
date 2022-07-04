class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        priority_queue<int> pq(nums.begin(),nums.end());
        int ans;
        for(int i=0;i<k;i++){
            if(!pq.empty()){
                ans = pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};