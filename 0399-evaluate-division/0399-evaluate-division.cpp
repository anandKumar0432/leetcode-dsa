class Solution {
public:

    void dfs(string from , string to, unordered_map<string, unordered_map<string, double>>& gr,  
                unordered_set<string>&  vis, double& ans, double temp){
        if(vis.find(from) != vis.end()) return;
        vis.insert(from);
        if(from == to) {
            ans = temp;
            return;
        }
        for(auto& it : gr[from]){
            dfs(it.first, to, gr, vis, ans, temp*it.second);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> gr;

        for(int i=0; i<equations.size(); i++){
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            gr[dividend][divisor] = values[i];
            gr[divisor][dividend] = 1.0/values[i];
        }

        vector<double> res;
        
        for(int i=0; i<queries.size(); i++){
            string from = queries[i][0];
            string to = queries[i][1];
            if(gr.find(from) == gr.end() || gr.find(to) == gr.end()){
                res.push_back(-1.0);
            }else{
                unordered_set<string> vis;
                double ans = -1.0;
                double temp = 1.0;
                dfs(from, to, gr, vis, ans, temp);
                res.push_back(ans);
            }
        }

        return res;
    }
};