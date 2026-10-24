class Solution {
public:
    //---------------BRUTE FORCE--------------------
    // bool dfs(int node, int target, vector<int>& vis,
    //          vector<vector<int>>& gr) {
    //     if (node == target) return true;

    //     vis[node] = 1;

    //     for (int neighbor : gr[node]) {
    //         if (!vis[neighbor]) {
    //             if (dfs(neighbor, target, vis, gr))
    //                 return true;
    //         }
    //     }

    //     return false;
    // }

    // vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    //     int n = edges.size();
    //     vector<vector<int>> gr(n + 1);

    //     for (auto& edge : edges) {
    //         gr[edge[0]].push_back(edge[1]);
    //         gr[edge[1]].push_back(edge[0]);
    //     }

    //     for (int i = n - 1; i >= 0; i--) {
    //         int u = edges[i][0];
    //         int v = edges[i][1];

    //         gr[u].erase(find(gr[u].begin(), gr[u].end(), v));
    //         gr[v].erase(find(gr[v].begin(), gr[v].end(), u));

    //         vector<int> vis(n + 1, 0);

    //         if (dfs(u, v, vis, gr)) {
    //             return {u, v};
    //         }

    //         gr[u].push_back(v);
    //         gr[v].push_back(u);
    //     }

    //     return {};
    // }

    vector<int> rank, parent;
    
    int findUParent(int node){
        if(parent[node] == node) return node;

        return parent[node] = findUParent(parent[node]);
    }
    bool unionByRank(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) return true;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        } else{
            parent[pv] = pu;
            rank[pu]++;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i=1; i<= n; i++){
            parent[i] = i;
        }

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(unionByRank(u, v)){
                return {u, v};
            }
        }


        return {};
    }
};