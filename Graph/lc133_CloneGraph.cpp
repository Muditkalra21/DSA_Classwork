#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {

        if(node == NULL)
            return NULL
        if(mp.find(node) != mp.end())
            return mp[node];
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto it : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(it));
        }
        return clone;
    }
};
