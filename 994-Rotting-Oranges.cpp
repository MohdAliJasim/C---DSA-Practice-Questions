class Solution {
public:
    int r ,c, mini = 0;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0 ;i < r;i++){
            for(int j = 0;j < c;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            mini++;
            for(int i =0  ;i < size;i++){
                pair<int,int> p = q.front();
                q.pop();
                int x= p.first;
                int y = p.second;
                for(int k = 0; k < 4;k++){
                    int ii = x + dx[k]; int jj = y + dy[k];
                    if(ii < 0 or ii >= r or jj <0 or jj >= c or grid[ii][jj] == 0 or grid[ii][jj] == 2) continue;

                    grid[ii][jj] = 2;
                    q.push({ii,jj}); 
                }
            }
        }
        for(int i =0;i < r ;i++){
            for(int j = 0; j < c;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        if(mini == 0) return 0;
        return mini-1;
    }
};