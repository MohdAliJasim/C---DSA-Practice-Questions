class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<bool> & visited, int source, vector<int> &res){
        visited[source] =true;

        for(int nbr : edges[source]){
            if(!visited[nbr]){
                dfs(edges, visited, nbr, res);
            }
        }
        res.push_back(source);

    }

    void bfs(vector<vector<int>>& edges, vector<int>& res, int n){
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i =0 ;i < edges.size();i++){
            for(int nbr: edges[i]){
                indegree[nbr]++;
            }
        }

        for(int i= 0 ;i < n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int nbr: edges[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);

        for(int i =0 ;i < prerequisites.size();i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false);
        vector<int> res;
        bfs(edges,res,numCourses);
        // reverse(res.begin(),res.end());
        // if(res.size() == numCourses){
        //     return res;
        // }
        // res.clear();
        // return res;
        if(res.size() != numCourses) res.clear();
        return res;
    }
};