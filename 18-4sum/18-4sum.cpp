class Solution {
public:    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> ans;
        if (nums.empty())
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int target_2 = (long long int)target-(long long int)nums[i]-(long long int)nums[j];
                int first = j+1;
                int last = n-1;
                while(first<last){
                    long long int sum =(long long int) nums[first]+(long long int) nums[last];
                    if(sum<target_2) first++;
                    else if(sum>target_2) last--;
                    else{
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[first];
                        temp[3] = nums[last];
                        ans.push_back(temp);
                        while(first < last and nums[first]==temp[2]) first++;
                        while(first<last and nums[last]==temp[3]) last--;
                    }
                }
                while(j+1<n and nums[j+1]==nums[j]) j++;
            }
            while(i+1<n and nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};