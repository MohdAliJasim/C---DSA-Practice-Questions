class Solution {
public:
    int longestCycleLn = -1;
    void dfs(vector<int>& edges, vector<bool> &visited, vector<int>& cp, int source , int len){
        len++;
        visited[source] =true;
        cp[source] = len;
        int nbr = edges[source];
        if(nbr != -1){
            if(!visited[nbr]){
                dfs(edges,visited,cp,nbr,len);
            }
            else if(cp[nbr] != 0){
                    int newLn = cp[source]- cp[nbr] + 1;
                    longestCycleLn = max(longestCycleLn , newLn);
                }
        }
        
        cp[source] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n,false);
        vector<int> cp(n,0);
        for(int i =0 ;i < n;i++){
            if(!visited[i]){
                dfs(edges, visited, cp, i , 0);
            }
        }
        return longestCycleLn;
    }
};