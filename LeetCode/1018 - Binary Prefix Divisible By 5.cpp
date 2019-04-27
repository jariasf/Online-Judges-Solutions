/*******************************************
 ***Problema: Binary Prefix Divisible By 5
 ***ID: 1018
 ***Juez: LeetCode
 ***Tipo: Math, State Machine
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int nextState(int cur, int val ){
        if( cur == 0 ){
            if( val == 1 ) return 1;
            else return 0;
        }
        
        if( cur == 1 ){
            if( val == 1 ) return 3;
            else return 2;
        }
        
        if( cur == 2 ){
            if( val == 1 ) return 0;
            else return 4;
        }
        
        if( cur == 3 ){
            if( val == 1 ) return 2;
            else return 1;
        }
        
        if( cur == 4 ){
            if( val == 1 ) return 4;
            else return 3;
        }
        return -1;
    }
    
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> res(n, false);
        int start = 0;
        for( int i = 0 ; i < n ; ++i ){
            start = nextState(start, A[i]);
            if( start == 0 ) res[i] = true;
        }
        return res;
    }
};
