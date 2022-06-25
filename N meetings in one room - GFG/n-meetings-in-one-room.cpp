// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 
class Meeting{
    public:
     
    int start;
    int end;
    Meeting(int s,int e){
        start = s;
        end = e;
    }
};
bool comp(Meeting a,Meeting b){
    return a.end<b.end;
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        //Steps Sort According to End Time
        //Select A Meeting and Store  the end time in the variable and increase the count
        vector<Meeting> meetings;
        
        for(int i=0;i<n;i++){
            Meeting meeting = Meeting(start[i],end[i]);
            meetings.push_back(meeting);
        }
        sort(meetings.begin(),meetings.end(),comp);
        int endTime = meetings[0].end;
        int count= 1;
        for(int i=1;i<n;i++){
            if(meetings[i].start>endTime){
                count++;
                endTime = meetings[i].end;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends