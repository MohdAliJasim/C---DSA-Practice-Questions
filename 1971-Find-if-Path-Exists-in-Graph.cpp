class Solution {
public:

    void dfs(vector<vector<int>>& edges, int v, int destination ,unordered_map<int, bool>& map,bool &flag){
           if(v == destination){
                    flag = true;
                    return;
                } 

            for(int i = 0 ;i < edges[v].size();i++){   
                if(map[edges[v][i]] != true){
                    map[edges[v][i]] = true;
                    dfs(edges, edges[v][i], destination,map,flag);                      
                    if(flag) return;
                }
            }
           
    }   

    void createAdj(vector<vector<int>> & adj , vector<vector<int>>& edges){
        for(int i =0 ;i < edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        createAdj(adj, edges);
        unordered_map<int , bool> map;
        if(source == destination ) return true;
        bool flag = false;
         dfs(adj, source, destination, map,flag);
         return flag;
    }
};