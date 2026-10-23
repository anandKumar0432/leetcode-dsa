class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n);
        vector<int> res;
        vector<vector<int>> adj(n);

        if(n <= 0){
            return res;
        }
        if(n == 1){
            res.push_back(0);
            return res;
        }

        for(auto el : edges){
            deg[el[0]]++;
            deg[el[1]]++;

            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(deg[i] == 1) q.push(i);
        }
        while(n > 2){
            int size = q.size();
            n -= size;

            while(size > 0){
                int el = q.front();
                q.pop();
                
                for(auto neighbor : adj[el]){
                    deg[neighbor]--;
                    if(deg[neighbor] == 1) q.push(neighbor);
                }
                size--;
            }
        }

        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};