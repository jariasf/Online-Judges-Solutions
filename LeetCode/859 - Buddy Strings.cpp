/*******************************************
 ***Problema: Buddy Strings
 ***ID: 859
 ***Juez: LeetCode
 ***Tipo: Ad hoc, counting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool buddyStrings(string &A, string &B) {
        if( A.size() != B.size() ) return false;
        
        int left_index, right_index;
        left_index = right_index = -1;
        vector<int> cnt(26);
        for( int i = 0 ; i < A.size(); ++i ){
            if( A[i] != B[i] ){
                if( left_index == -1 ) left_index = i;
                else if( right_index == -1 ) right_index = i;
                else return false;
            }
            cnt[ A[i] - 'a' ]++;
        }
        
        if(left_index == -1){
            for( int i = 0 ; i < 26 ; ++i ){
                if( cnt[i] > 1 ) return true;
            }
            return false;
        }
        if(right_index == -1) return false;
        
        return (A[left_index] == B[right_index] && A[right_index] == B[left_index]);
    }
};
