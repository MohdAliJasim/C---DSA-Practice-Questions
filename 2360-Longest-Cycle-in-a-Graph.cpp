class Solution {
public:
    int maxi = -1;

    void dfs(vector<int>& edges, vector<bool> &visited, vector<int> &cp, int source , int len){
        len++;
        visited[source] = true;
        cp[source] = len;
        int nbr = edges[source];
        if(nbr == -1){
            cp[source] = 0;
            len--;
            return;
        }
        if(!visited[nbr]){
            dfs(edges, visited, cp ,nbr , len);
        }
        else if(cp[nbr] != 0){
            int mlen = len - cp[nbr] +1;
            maxi = max(mlen  , maxi);
        }
        cp[source] = 0;
        len--;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>cp(n,0);
        vector<bool> visited(n,false);

        for(int i =0;i <n ;i++){
            if(!visited[i]){
                dfs(edges, visited, cp, i,0);
            }
        }
        return maxi;
    }
};