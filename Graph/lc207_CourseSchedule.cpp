#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCyclicDFS(vector<vector<int> > &adj, vector<bool> &vis, vector<bool> &dfsvis, int node)
    {
        dfsvis[node] = true;
        vis[node] = true;
        for(auto it : adj[node] )
        {
            if(!vis[it])
            {
                bool iscycle = isCyclicDFS(adj,vis,dfsvis,it);
                if(iscycle)
                {
                    return true;
                }
            }
            else if(dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> dfsvis(numCourses,false);
        for(int i = 0; i<adj.size(); i++)
        {
            if(!vis[i])
            {
                bool iscycle = isCyclicDFS(adj,vis,dfsvis,i);
                if(iscycle)
                {
                    return false;
                }
            }
        }
        return true;
    }
};