// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void calculateSubsetSum(vector<int> arr,int sum,int index,vector<int> &ans,int N){
        if(index == N){
            ans.push_back(sum);
            return;
        }
        
        //pick the element
        calculateSubsetSum(arr,sum+arr[index],index+1,ans,N);
        
        //not pick the element
        calculateSubsetSum(arr,sum,index+1,ans,N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        calculateSubsetSum(arr,0,0,ans,N);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends