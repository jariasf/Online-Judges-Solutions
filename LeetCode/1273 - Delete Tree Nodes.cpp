/*******************************************
 ***Problema: Delete Tree Nodes
 ***ID: 1273
 ***Juez: LeetCode
 ***Tipo: Topological Sort
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    typedef long long LL;
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int> tree[nodes + 5];
        vector<LL> values(value.begin(), value.end());
        
        vector<int> degree(nodes);
        for( int i = 1 ; i < nodes; ++i ){
            degree[parent[i]]++;
            tree[parent[i]].push_back(i);
        }
        
        queue<int> Q;
        for( int i = 0 ; i < nodes; ++i ){
            if( degree[i] == 0 ){
                Q.push(i);
            }
        }
        
        while( !Q.empty()){
            int cur = Q.front(); Q.pop();
            if( parent[cur] != -1 ){
                values[parent[cur]] += values[cur];
                if( --degree[parent[cur]] == 0 )
                    Q.push(parent[cur]);
            }
        }
        
        // Topological Sort
        Q.push(0);
        int total = 0;
        while( !Q.empty() ){
            int cur = Q.front(); Q.pop();
            if( values[cur] == 0 ) continue;
            total++;
            for( int i = 0 ; i < tree[cur].size(); ++i ){
                int u = tree[cur][i];
                Q.push(u);
            }
        }
        
        return total;
        
    }
};
