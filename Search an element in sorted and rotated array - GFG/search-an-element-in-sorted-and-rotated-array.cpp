// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int target) {
    int l = 0;
    int h = arr.size()-1;
    while(l<=h){
            int mid = (l+h)>>1;
            if(target==arr[mid]) return mid;
            if(arr[l]<=arr[mid]){
                if(arr[l]<=target and arr[mid]>=target){
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }else if(arr[h]>=arr[mid]){
                if(arr[mid]<=target and arr[h]>=target){
                    l = mid+1;
                }else{
                    h = mid-1;
                }
            }
        }
        return -1;
}