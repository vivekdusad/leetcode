// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isBipartiteHelper(vector<int> adj[],vector<int> &colr,int node){
        if(colr[node]==-1) colr[node] = 1;
        
        for(auto v:adj[node]){
            if(colr[v]==-1){
                colr[v] = 1-colr[node];
                if(!isBipartiteHelper(adj,colr,v)) return false;
            }else if(colr[v]==colr[node]) return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colr(V,-1);
	    for(int i=0;i<V;i++){
	        if(colr[i]==-1){
	            if(!isBipartiteHelper(adj,colr,i)) return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends