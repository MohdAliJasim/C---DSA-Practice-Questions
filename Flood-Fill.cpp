class Solution {
public:
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        int og = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for(int i = 0 ;i < 4;i++){
                int ii = x+dx[i];
                int jj = y + dy[i];

                if(ii < 0 or jj < 0 or ii >= image.size() or jj >= image[0].size() or image[ii][jj] != og)
                    continue;
                
                image[ii][jj] = color;
                q.push({ii,jj});
            }
        }
        return image;
    }
};