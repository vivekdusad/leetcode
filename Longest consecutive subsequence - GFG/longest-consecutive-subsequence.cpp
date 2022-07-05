// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      if(n==0) return 0;
      if(n==1) return 1;
      int ans=0;
      unordered_set<int> hashset(arr,arr+n);
      for(int i=0;i<n;i++){
          if(!hashset.count(arr[i]-1)){//first element of the sequence
              int currentStreak=1;
              int currentNum=arr[i];
              while(hashset.count(currentNum+1)){
                  currentStreak++;
                  currentNum++;
              }
              ans = max(ans,currentStreak);
          }
          
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends