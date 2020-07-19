/*******************************************
 ***Problema: Course Schedule II
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: Topological Sort
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prereq) {
        
        vector<int> indegree(V);
        vector<vector<int> > adj(V);
        queue<int> Q;        
        vector<int> res;        
        for( int i = 0 ; i < prereq.size(); ++i ){
            adj[ prereq[i][1]].push_back( prereq[i][0]);
            indegree[prereq[i][0]]++;
        }

        for( int i = 0 ; i < V ; ++i )
            if( indegree[i] == 0 )
                Q.push(i);
        
        while( !Q.empty() ){
            int cur = Q.front(); Q.pop();
            res.push_back(cur);
            for( int i = 0 ; i < adj[cur].size(); ++i ){
                int v= adj[cur][i];
                if( --indegree[v] == 0 ){
                    Q.push(v);
                }
            }
        }

        if( res.size() != V ) return {};
        return res;
    }
};
