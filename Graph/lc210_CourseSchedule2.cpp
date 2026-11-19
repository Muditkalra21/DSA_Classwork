#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool DFScycle(vector<vector<int> > &adj,vector<bool> &vis, vector<bool> &dfsvis, stack<int> &st, int node)
    {
        vis[node] = true;
        dfsvis[node] = true;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(DFScycle(adj,vis,dfsvis,st,it))
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
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses);
        vector<bool> dfsvis(numCourses);
        stack<int> st;
        for(int i = 0; i<adj.size(); i++)
        {
            if(!vis[i])
            {
                if(DFScycle(adj,vis,dfsvis,st,i))
                {
                    return {};
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};