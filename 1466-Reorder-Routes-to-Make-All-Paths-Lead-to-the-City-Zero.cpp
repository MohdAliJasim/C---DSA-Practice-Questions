class Solution {
public:

    void dfs(int source , vector<vector<int>>&forward,vector<vector<int>>& backward, vector<bool> & visited,int &ans){
        visited[source] = true;

        for(int nbr : forward[source]){
            if(!visited[nbr]){
                ans +=1;
                dfs(nbr, forward,backward, visited,ans);
            }
        }
        for(int nbr: backward[source]){
            if(!visited[nbr])
            dfs(nbr, forward, backward , visited, ans);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n), backward(n);
        vector<bool> visited(n);
        for(int i =0 ;i < connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];

            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        int ans = 0;
        dfs(0,forward,backward,visited,ans);
        return ans;
    }
};