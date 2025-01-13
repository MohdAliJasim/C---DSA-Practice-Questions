class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> edges(n);
        for(int i= 0 ;i < prerequisites.size();i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(n,0);
        for(int i=0 ;i < n;i++){
            for(int nbr: edges[i]) indegree[nbr]++;
        }
        queue<int> q;
        for(int i=0 ;i < n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int nbr : edges[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        if(res.size() == n) return true;
        return false;
    }
};