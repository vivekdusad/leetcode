// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        //  int n = nums.size();
        int low=0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            switch(nums[mid]){
                case 0: swap(nums[low++],nums[mid++]);
                        break;
                case 1: mid++;
                        break;
                case 2: swap(nums[high--],nums[mid]);
                        break;

            }
        }
        
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends