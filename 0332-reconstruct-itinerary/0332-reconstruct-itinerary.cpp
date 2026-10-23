class Solution {
public:
    map<string, vector<string>> adj;
    vector<string> res;
    // bool solve(map<string, vector<string>>& adj, string fromAirport, vector<string>& res, vector<string>& path, int n){
    //     path.push_back(fromAirport);
    //     if(path.size() == n+1) {
    //         res = path;
    //         return true;
    //     }
    //     vector<string>& neigh = adj[fromAirport];
    //     for(int i=0; i<neigh.size(); i++){
    //         string toAirport = neigh[i];
    //         neigh.erase(neigh.begin()+i);
    //         if(solve(adj, toAirport, res, path, n)) return true;
    //         neigh.insert(neigh.begin()+i, toAirport);
    //         i++;
    //     }

    //     path.pop_back();
    //     return false;
    // }


    void dfs(string fromAirport){

        while(!adj[fromAirport].empty()){
            string toAirport = adj[fromAirport].back();
            adj[fromAirport].pop_back();
            dfs(toAirport);
        }

        res.push_back(fromAirport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // sort(tickets.begin(), tickets.end());
        // int n = tickets.size();
        for(int i=0; i<tickets.size(); i++){
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }
        // string fromAirport = "JFK";
        // vector<string> res;
        // vector<string> path;
        
        // solve(adj, fromAirport, res, path, n);
        
        for(auto& [airport, dest] : adj){
            sort(dest.rbegin(), dest.rend());
        }

        dfs("JFK");
        reverse(res.begin(), res.end());

        return res;
    }
};