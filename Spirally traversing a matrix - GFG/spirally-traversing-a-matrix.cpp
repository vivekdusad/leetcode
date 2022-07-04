// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int m, int n) 
    {
        vector<int> ans;
        if(m==0) return ans;
        vector<vector<int>> seen(m,vector<int>(n,0));
        int dr[]={0,1,0,-1,};
        int dc[]={1,0,-1,0};
        int x = 0,y=0,di=0;
        
        for(int i=0;i<m*n;i++){
            ans.push_back(matrix[x][y]);
            seen[x][y]=1;
            int newX = x+dr[di];
            int newY = y+dc[di];
            
            if(0<=newX and newX<m and 0<=newY and newY<n and !seen[newX][newY]){
                x = newX;
                y = newY;
            }else{
                di =(di+1)%4;
                x +=dr[di];
                y +=dc[di];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends