class Solution {
public:
    bool isCycle(int node, vector<int>& vis, vector<int>& pathVis, vector<int>& res, vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node] = 1;

        for(int it : adj[node]){
            if(!vis[it]){
               if(isCycle(it, vis, pathVis, res, adj)) return true;
            }else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        res.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> res;

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(isCycle(i, vis, pathVis, res, adj)) return {};
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};