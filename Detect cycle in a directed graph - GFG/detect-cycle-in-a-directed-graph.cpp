// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  
 private:
 bool canFinishHelper(int index,vector<int> adj[], int numCur,vector<int> &visited,vector<int> &recStk){
        
        visited[index] = recStk[index]= 1;     
        
        for(auto it: adj[index]){
            if(visited[it]==0 and canFinishHelper(it,adj,numCur,visited,recStk)){
                return true;
            }else if(recStk[it]==1){
                return true;
            }
        }
        
        recStk[index] = 0;
        return false;
    }
    vector<int> calculateIndegree(vector<int> adj[],int V){
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        return indegree;
    }
  
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        
        //storing which is on the recursion stack
        vector<int> recStk(V,0);
        
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
               if(canFinishHelper(i,adj,V,visited,recStk)){
                   return true;
               }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends