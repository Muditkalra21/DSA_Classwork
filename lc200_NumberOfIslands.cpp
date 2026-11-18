#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool> > &vis, int x, int y)
    {
        vis[x][y] = true;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int i = 0; i<4; i++)
        {
            int newx = dx[i] + x;
            int newy = dy[i] + y;
            if(newx >= 0 && newy >= 0 && newx < grid.size() && newy < grid[0].size() &&!vis[newx][newy] && grid[newx][newy] == '1')
            {
                dfs(grid,vis,newx,newy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool> > vis(grid.size(),vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[i].size(); j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};