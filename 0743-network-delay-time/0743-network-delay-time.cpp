class Solution {
public:
    // void dfs(vector<vector<vector<int>>>& gr, int node, int val,
    //          vector<int>& mini, vector<int>& vis) {
    //     vis[node] = 1;

    //     for (auto it : gr[node]) {
    //         int neighbor = it[0];
    //         int weight = it[1];

    //         if (val + weight < mini[neighbor]) {
    //             mini[neighbor] = val + weight;
    //             dfs(gr, neighbor, val + weight, mini, vis);
    //         }
    //     }
    // }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> gr(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            gr[u].push_back({v, w});
        }

        // vector<int> mini(n + 1, INT_MAX);
        // vector<int> vis(n + 1, 0);
        // mini[k] = 0;

        // dfs(gr, k, 0, mini, vis);

        // int min_val = 0;

        // for (int i = 1; i <= n; i++) {
        //     if (mini[i] == INT_MAX) return -1;
        //     min_val = max(min_val, mini[i]);
        // }

        // return min_val;

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for(auto it : gr[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (dis > dist[node]) continue;
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int min_val = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            min_val = max(min_val, dist[i]);
        }

        return min_val;
    }
};