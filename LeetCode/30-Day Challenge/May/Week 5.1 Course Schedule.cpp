/*******************************************
 ***Problema: Course Schedule
 ***ID: Week5.1
 ***Juez: LeetCode
 ***Tipo: Topological Sort
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses, vector<int>());
        vector<int> indegree(numCourses);
        for( int i = 0 ; i < prerequisites.size()  ; ++i ){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> Q;
        for( int i = 0 ; i < numCourses ; ++i )
            if( indegree[i] == 0 )
                Q.push(i);
        
        int cnt = 0;
        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            cnt++;
            for( int i = 0 ; i < adj[u].size(); ++i ){
                int v = adj[u][i];
                if( --indegree[v] == 0 )
                    Q.push(v);
            }
        }
        return cnt == numCourses;
    }
};
