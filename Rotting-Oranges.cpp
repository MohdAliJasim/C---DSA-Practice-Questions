class Solution {
public:
    vector<int>dx = {0,0,-1,1};
    vector<int>dy = {-1,1,0,0};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        for(int i =0 ;i < grid.size();i++){
            for(int j =0 ; j <grid[0].size();j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        int second = 0;

        while(!q.empty()){
            int size = q.size();
                second++;
            for(int i= 0;i < size;i++){
                pair<int,int>p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(int k = 0 ; k < 4;k++){
                    int ii = x + dx[k];
                    int jj= y + dy[k];

                    if(ii < 0 or jj < 0 or ii >= grid.size() or jj >= grid[0].size() or 
                    grid[ii][jj] == 0 or grid[ii][jj] == 2 ) continue;

                    grid[ii][jj] = 2;
                    q.push({ii,jj});
                }
            }
        }
        for(int i= 0 ;i < grid.size();i++){
            for(int j =0 ;j< grid[0].size();j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return second==0?0: second-1;
    }
};