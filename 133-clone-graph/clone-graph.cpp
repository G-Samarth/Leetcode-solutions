/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map){
        if(!node)
            return NULL;

        if(node->neighbors.empty())
            return new Node(node->val);

        Node* clone = new Node(node->val);
        vector<Node*> clonedNeighbors;
        map[node] = clone;
        for(auto it : node->neighbors){
            if(map.find(it) != map.end())
                clonedNeighbors.push_back(map[it]);
            else
                clonedNeighbors.push_back(dfs(it, map));
        }

        clone->neighbors = clonedNeighbors;
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        return dfs(node, map);
    }
};