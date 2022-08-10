class Solution {
public:
    void calcuate(vector<int> &nums,vector<int> &left,vector<int> &right,int n){
        stack<int> st;
        
        for(int i=0;i<n;i++){
            int curr  = nums[i];
            while(!st.empty() and nums[st.top()]>=curr) st.pop();
            
            if(st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        
        for(int i=n-1;i>=0;i--){
            int curr  = nums[i];
            while(!st.empty() and nums[st.top()]>=curr) st.pop();
            
            if(st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
            
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        //formula
        //Max => (right-left)*a[i]
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        calcuate(heights,left,right,n);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]+1)*heights[i]);
        }
        return ans;
    }
};