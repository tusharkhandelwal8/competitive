class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        vector<pair<int,int>> move = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0,0});
        
        int n = grid.size(), m = grid[0].size();
        
        int dis[n][m];
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) dis[i][j] = 1000000000;
        
        dis[0][0] = 0;
        
        while(q.size())
        {
            vector<int> curr = q.top(); q.pop();
            
            int i = curr[1], j = curr[2], time = curr[0];
            if(time > dis[i][j]) continue;

            for(int k=0; k<4; k++)
            {
                int ii = i+move[k].first, jj = j+move[k].second;
                
                if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                
                int extra = (grid[ii][jj]-time) % 2;
                if(extra != 0) extra = 0;
                else extra = 1;

                int curr_time = max(grid[ii][jj]+extra , time+1);
                
                if(curr_time < dis[ii][jj])
                {
                    dis[ii][jj] = curr_time;
                    q.push({curr_time,ii,jj});
                }
            }
        }
        
        return dis[n-1][m-1];
        
    }
};
