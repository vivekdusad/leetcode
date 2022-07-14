// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> mst(V,false);
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > todos;
        todos.push({0,0});
        vector<int> key(V,INT_MAX);
        key[0] = 0;
        int ans = 0;
        while(!todos.empty()){
            int e = (todos.top()).second;
            
            todos.pop();
            mst[e] = true;
            for(auto it:adj[e]){
                int v = it[0];
                int weight = it[1];
                if((weight < key[v]) and mst[v]==false){
                    key[v] =weight;
                    
                    todos.push({key[v],v});
                }
            }
            
        }
        ans = accumulate(key.begin(),key.end(),0);
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends