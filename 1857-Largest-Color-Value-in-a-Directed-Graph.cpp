class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i= 0;i < edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        vector<vector<int>> cnt(n, vector<int>(26,0));
        int ans =0;
        queue<int> q;
        for(int i=0 ;i < indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        int processed =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            processed++;
            cnt[node][colors[node] - 'a']++;

            ans = max(ans, cnt[node][colors[node]-'a']);

            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);

                for(int i =0 ;i < 26;i++){
                    cnt[nbr][i] = max(cnt[nbr][i], cnt[node][i]);
                }
            }
        }
        return processed==n?ans:-1;
    }
};