// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 
bool comparator(vector<int> a,vector<int>b){
        return a[0]<b[0];
}

class Solution {
public:
    bool isOverlaping(vector<int> a,vector<int> b){
        return a[1]>=b[0];
    }
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),comparator);
        ans.push_back(intervals[0]);
         for(int i=1;i<intervals.size();i++){
             
             bool isOverLapped = isOverlaping(ans.back(),intervals[i]);
            //  cout<<isOverLapped<<endl;
             if(isOverLapped){
                 vector<int> last = ans.back();
                 ans.pop_back();
                 last[1] = max(last[1],intervals[i][1]);
                 ans.push_back(last);
             }else{
                 ans.push_back(intervals[i]);
             }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends