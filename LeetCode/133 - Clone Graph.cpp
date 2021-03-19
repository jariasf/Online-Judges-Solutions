/*******************************************
 ***Problema: Clone Graph
 ***ID: 133
 ***Juez: LeetCode
 ***Tipo: BFS | DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

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

//DFS
class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if( node == NULL ) return NULL;
        if( visited.find(node) != hash.end() )
            return visited[node];
        Node* cur = new Node(node -> val);
        visited[node] = cur;
        for( Node* next: node -> neighbors){
            cur -> neighbors.push_back(cloneGraph(next));
        }
        return cur;
    }
};

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if( node == NULL ) return NULL;
        Node* root = new Node(node -> val);
        queue<pair<Node *, Node *> > Q;
        Q.push(make_pair(node, root));
        unordered_map<int, Node*> visited;
        visited[node -> val] = root;
        while( !Q.empty() ){
            pair<Node*, Node*> p = Q.front(); Q.pop();
            node = p.first;
            Node* copy_node = p.second;
            for( int i = 0 ; i < (node -> neighbors).size() ; ++i ){
                Node* current = (node -> neighbors)[i];
                Node* copy_current;
                if( visited.find(current -> val) == visited.end() ){
                    copy_current = new Node(current -> val);
                    Q.push(make_pair(current, copy_current));
                    visited[current -> val] = copy_current;
                }else{
                    copy_current = visited[current -> val];
                }
                (copy_node -> neighbors).push_back(copy_current);
            }
        }
        return root;
    }
};
