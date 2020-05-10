/*******************************************
 ***Problema: Find the Town Judge
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Using 1 array
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int sz = trust.size();
        vector<int> cnt(N);
        for( int i = 0 ; i < sz ; ++i ){
            cnt[trust[i][1] - 1]++;
            cnt[trust[i][0] - 1]--;
        }
        
        for( int i = 0 ; i < N ; ++i ){
            if( cnt[i] == N - 1 )
                return i + 1;
        }
        return -1;
    }
};


// Using 2 arrays
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int sz = trust.size(), res = -1;
        vector<int> indegree(N), outdegree(N);
        for( int i = 0 ; i < sz ; ++i ){
            indegree[trust[i][1] - 1]++;
            outdegree[trust[i][0] - 1]++;
        }
        
        int cnt = 0;
        for( int i = 0 ; i < N ; ++i ){
            if( indegree[i] == N - 1 && outdegree[i] == 0 ){
                res = i + 1;
                cnt++;
                if( cnt > 1 ) 
                    return -1;
            }
        }
        return res;
    }
};
