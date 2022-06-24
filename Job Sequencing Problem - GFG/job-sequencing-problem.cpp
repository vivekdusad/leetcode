// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool jobComparator(Job a,Job b){
    if(a.profit>b.profit){
        return true;
    }
    return false;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        int max_dead = INT_MIN;
        for(int i=0;i<n;i++){
            max_dead = max(max_dead,arr[i].dead);
        }
        vector<int> jobs(max_dead,-1);
        int totalProfit = 0;
        sort(arr,arr+n,jobComparator);
        for(int i=0;i<n;i++){
            Job job = arr[i];
            int j = job.dead-1;
            // cout<<job.profit<<job.dead<<endl;
            if(jobs[j] != -1){
                while(j>=0 && jobs[j] != -1) j--;
                if(j<0) continue;
            }
            jobs[j]=job.id;
            totalProfit += job.profit;
        }
        int count = 0;
        for(auto it:jobs){
            // cout<<it<<endl;
            if(it != -1){
                count++;
            }
        }
        return {count,totalProfit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends