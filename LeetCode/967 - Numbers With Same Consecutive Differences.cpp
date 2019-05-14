/******************************************************
 ***Problema: Numbers With Same Consecutive Differences
 ***ID: 967
 ***Juez: LeetCode
 ***Tipo: Brute Force, Recursion
 ***Autor: Jhosimar George Arias Figueroa
 *****************************************************/

class Solution {
public:
    vector<int> res;
    int N,K;
    int solve(int pos, int lastVal, int num){
        if( pos == N ){
            res.push_back(num);
            return 1;    
        }
        int result = 0;
        if( lastVal + K <= 9 )
            result += solve(pos + 1, lastVal + K, num * 10 + lastVal + K );
        if( lastVal - K >= 0 && K > 0 )
            result += solve(pos + 1, lastVal - K, num * 10 + lastVal - K );
        return result;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        N = n; K = k;
        res.clear();
        
        if( n == 1 ){
            res.push_back(0);
        }
        int result = 0;
        for( int i = 1 ; i <= 9 ; ++i ){
            result += solve(1, i, i);
        }
        return res;
    }
};
