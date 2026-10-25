class Solution {
public:
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
        } else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }

        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1, 0);
        parent.resize(n+1);

        vector<int> indeg(n+1, -1);
        int bl1 = -1;
        int bl2 = -1;
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(indeg[v] == -1){
                indeg[v] = i;
            }else{
                bl1 = i;
                bl2 = indeg[v];
            }
        }

        for(int i=1; i<= n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            if(i == bl1) continue;
            int u = edges[i][0];
            int v = edges[i][1];

            if(unionByRank(u, v)){
                if(bl1 == -1){
                    return edges[i];
                }else {
                    return edges[bl2];
                }
            }
        }
        return edges[bl1];
    }
};