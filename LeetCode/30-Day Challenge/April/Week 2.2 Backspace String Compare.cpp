/*******************************************
 ***Problema: Backspace String Compare
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    // next valid char (different than #)
    int nextValidIndex(string &S, int i){
        int cnt = 0;
        while( i >= 0 && (cnt > 0 || S[i] == '#') ){
            cnt += S[i--] == '#' ? 1 : -1;
        }
        return i;
    }
    
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        
        while(i >= 0 || j >= 0 ){
            //next valid char
            int next_i = nextValidIndex(S, i);
            int next_j = nextValidIndex(T, j);
            
            //empty or different char
            if( next_i < 0 || next_j < 0 || S[next_i] != T[next_j]) 
                return next_i < 0 && next_j < 0; 

            i = next_i - 1; j = next_j - 1;
        }
        
        return i < 0 && j < 0;
    }
};
