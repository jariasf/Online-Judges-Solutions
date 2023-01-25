/*******************************************
 ***Problema: Find Closest Node to Given Two Nodes
 ***ID: Week 4.4
 ***Juez: LeetCode
 ***Tipo: BFS | DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> bfs(vector<int> &edges, int u){
        int V = edges.size();
        queue<int> Q;
        vector<int> dist(V, -1);
        dist[u] = 0;
        Q.push(u);
        while(!Q.empty()){
            u = Q.front(); Q.pop();
            int v = edges[u];
            if( v != -1 && dist[v] == -1 ){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> d1 = bfs(edges, node1);
        vector<int> d2 = bfs(edges, node2);
        int mini = INT_MAX, node = -1, maxi;
        for(int i = 0 ; i < edges.size(); ++i){
            if( d1[i] != -1 && d2[i] != -1){
                maxi = max(d1[i], d2[i]);
                if( mini > maxi ){
                    mini = maxi;
                    node = i;
                }
            }
        }
        return node;
    }
};
