class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        //step 1 handling snakes and ladder
        vector<int> connections(n*n+1,-1);
        bool flag = true;
        int node = 1;
        for(int i = n-1 ;i >= 0;i--){
            if(flag){
                for(int j = 0 ;j < n;j++){
                    if(board[i][j] != -1){
                        connections[node] = board[i][j];
                    }
                    node++;
                }
            }
            else{
                for(int j = n-1;j>=0;j--){
                    if(board[i][j] != -1){
                        connections[node] = board[i][j];
                    }
                    node++;
                }
            }
            flag = flag?0:1;
        }

        //step 2 making graph using connections
        unordered_map<int , vector<int>> graph;
        for(int i = 1 ; i <= n*n-1;i++){
            
            for(int j = 1; j <= 6;j++){
                int nbr = i + j;
                if(nbr > n*n) continue;
                if(connections[nbr] != -1){
                    graph[i].push_back(connections[nbr]);
                }
                else graph[i].push_back(nbr); 
            }
        }

        //step 3 calculating min moves to reach finishing point
        int level = 0;
        queue<int>q;
        vector<int> vis(n*n +1 );
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int pos = q.front();
                q.pop();
                if(pos == n*n) return level;
               
                for(int nbr : graph[pos]){
                    if(nbr > n*n) continue;
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};