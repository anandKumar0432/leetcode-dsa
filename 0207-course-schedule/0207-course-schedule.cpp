class Solution {
public:
    bool findCycle(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(int neighbor : graph[node]){
            if(!vis[neighbor]){
                if(findCycle(neighbor, graph, vis, pathVis)){
                    return true;
                }
            }else if(pathVis[neighbor]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> graph(numCourses, vector<int>());
         for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
         }

         vector<int> vis(numCourses, 0);
         vector<int> pathVis(numCourses, 0);
         for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(findCycle(i, graph, vis, pathVis)) return false;
            }
         }
         
         return true;
    }
};