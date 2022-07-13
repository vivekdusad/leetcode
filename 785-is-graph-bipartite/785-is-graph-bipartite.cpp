class Solution {
private:
    bool isBipartiteHelper(vector<vector<int>>& adj,vector<int> &colr,int node){
        if(colr[node]==-1) colr[node] = 1;
        
        for(auto v:adj[node]){
            if(colr[v]==-1){
                colr[v] = 1-colr[node];
                if(!isBipartiteHelper(adj,colr,v)) return false;
            }else if(colr[v]==colr[node]) return false;
        }
        return true;
    }
    bool DfsHelper(vector<vector<int>> &graph,int s,vector<int> &visited,vector<int> &selectedSet){
        visited[s] = 1;
        for(auto v:graph[s]){
            if(visited[v]==false){
                selectedSet[v] = 1;
                if(!DfsHelper(graph,v,visited,selectedSet)){
                    return false;
                }
                selectedSet[v] = -1;
                if(!DfsHelper(graph,v,visited,selectedSet)){
                    return false;
                }
                
            }else if(selectedSet[v]==selectedSet[s]){
                    return false;                
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> colr(V,-1);
	    for(int i=0;i<V;i++){
	        if(colr[i]==-1){
	            if(!isBipartiteHelper(adj,colr,i)) return false;
	        }
	    }
	    return true;
    }
};