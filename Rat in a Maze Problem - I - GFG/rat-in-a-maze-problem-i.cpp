// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(string temp,vector<vector<int>> &nums,int row,int col,int n,vector<string> &ans,vector<vector<bool>> &visited){
        if(row==n-1 and col==n-1){
            ans.push_back(temp);
            return;
        }
        //downwards
        if(row+1<n and !visited[row+1][col] and nums[row+1][col] == 1){
            visited[row][col]=1;
            solve(temp+'D',nums,row+1,col,n,ans,visited);
            visited[row][col]=0;
        }
        //upwards
        if(row-1>=0 and !visited[row-1][col] and nums[row-1][col] == 1){
            visited[row][col]=1;
            solve(temp+'U',nums,row-1,col,n,ans,visited);
            visited[row][col]=0;
        }
        //right
        if(col+1<n and !visited[row][col+1] and nums[row][col+1] == 1){
            visited[row][col]=1;
            solve(temp+'R',nums,row,col+1,n,ans,visited);
            visited[row][col]=0;
        }
        //left
        if(col-1>=0 and !visited[row][col-1] and nums[row][col-1] == 1){
            visited[row][col]=1;
            solve(temp+'L',nums,row,col-1,n,ans,visited);
            visited[row][col]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        string temp;
        // solve(m,0,0,n,ans,temp);
       if(m[0][0] ==1) solve(temp,m,0,0,n,ans,visited);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends