class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<bool> &visited, vector<bool> & current_path, int source){
        visited[source] =true;
        current_path[source] = true;

        for(int nbr : graph[source]){
            if(!visited[nbr]){
                bool res = dfs(graph , visited, current_path, nbr);
                if(res) return true;
            }
            else{
                if(current_path[nbr]) return true;
            }
        }
        current_path[source] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> current_path(n, false);
        vector<bool> res(n, true);
        for(int i= 0 ;i < graph.size();i++){
            if(!visited[i]){
                if(dfs(graph, visited, current_path, i)){
                    for(int i =0 ;i < graph.size();i++){
                        if(current_path[i]) res[i] = false;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0 ; i< n;i++){
            if(res[i]) ans.push_back(i);
        }
        return ans;
    }
};