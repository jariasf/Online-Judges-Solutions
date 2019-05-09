/*******************************************
 ***Problema: Find the Town Judge
 ***ID: 997
 ***Juez: LeetCode
 ***Tipo: Graph Theory, Indegree/Outdegree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();

        vector<int> indegree(N + 1, 0);
        vector<int> outdegree(N + 1, 0);
        for( int i = 0 ; i < n ; ++i ){
            int u = trust[i][0] - 1;
            int v = trust[i][1] - 1;
            indegree[v]++;
            outdegree[u]++;
        }
        
        for( int i = 0 ; i < N ; ++i ){
            if( indegree[i] == N - 1 && outdegree[i] == 0 ) return i + 1;
        }
        return -1;
    }
};
