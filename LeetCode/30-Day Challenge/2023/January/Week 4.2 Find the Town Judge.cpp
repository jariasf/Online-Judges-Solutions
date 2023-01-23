/*******************************************
 ***Problema: Find the Town Judge
 ***ID: Week 4.2
 ***Juez: LeetCode
 ***Tipo: Graphs - degree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n);
        vector<bool> trust_someone(n);
        for(vector<int> e:trust){
            int u = e[0] - 1, v = e[1] - 1;
            indegree[v]++;
            trust_someone[u] = true;
        }
        for(int i = 0 ; i < n ; ++i ){
            if(indegree[i] == n - 1 && !trust_someone[i] ){
                return i + 1;
            }
        }
        return -1;
    }
};
