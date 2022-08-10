class Solution {
    private:
        int maximumAreaHistogram(vector<int> &height){
        int n = height.size();
            stack<int> st;
            int maxArea = 0;
            for(int i=0;i<=n;i++){
                while(!st.empty() and (i==n or height[st.top()]>= height[i])){
                    int h = height[st.top()];
                    int width;
                    st.pop();
                    if(st.empty()) width = i;
                    else width = i-st.top()-1;
                    maxArea = max(maxArea,width*h);
                }
                st.push(i);
            }
            return maxArea;
        }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> height(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j] = 0;
            }
            maxArea = max(maxArea,maximumAreaHistogram(height));
        }
        return maxArea;
    }
};