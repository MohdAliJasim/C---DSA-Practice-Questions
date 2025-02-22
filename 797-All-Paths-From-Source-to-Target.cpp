class Solution {
public:

    void solve(int source , vector<vector<int>>& ans , vector<int>& temp, vector<vector<int>>& graph,int des){
        if(source == des){
            temp.push_back(source);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(source);
        for(int nbr : graph[source]){
            solve(nbr, ans, temp, graph,des);
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, ans , temp, graph,graph.size()-1);
        return ans;
    }
};