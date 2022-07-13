class Solution {
private:
    bool canFinishHelper(int index,vector<vector<int>> &preReq, int numCur,vector<int> &visited,vector<int> &recStk){
        
        visited[index] = recStk[index]= 1;     
        
        for(auto it: preReq[index]){
            if(visited[it]==0 and canFinishHelper(it,preReq,numCur,visited,recStk)){
                return true;
            }else if(recStk[it]==1){
                return true;
            }
        }
        
        recStk[index] = 0;
        return false;
    }
    
    vector<vector<int>> buildGraph(vector<vector<int>> &prerequisites,int numCourses){
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return graph;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //storing which elements we have aleready visited
        vector<int> visited(numCourses,0);
        
        //storing which is on the recursion stack
        vector<int> recStk(numCourses,0);
        
        //building adjancy list representation of the graph
        vector<vector<int>> graph = buildGraph(prerequisites,numCourses);
        
        
        for(int i=0;i<graph.size();i++){
            if(visited[i]==0){
               if(canFinishHelper(i,graph,numCourses,visited,recStk)){
                   return false;
               }
            }
        }
        
        return true;
    }
};