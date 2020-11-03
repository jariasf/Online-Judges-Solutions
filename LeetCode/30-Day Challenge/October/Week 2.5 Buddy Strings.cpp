/*******************************************
 ***Problema: Buddy Strings
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if( A.size() != B.size() ) return false;
        int n = A.size();
        int index = -1, cnt = 0;
        bool correct = false;
        for( int i = 0 ; i < n && cnt < 3  ; ++i ){
            if( A[i] != B[i] ){
                cnt++;
                if( index != -1 && A[index] == B[i] && B[index] == A[i] ){
                    correct = true;
                } 
                index = i;
            }
        }
        if( cnt > 2 ) return false;
        if( correct ) return true;
        
        if( cnt == 0 ){
            vector<int> hash(26);
            for(char c:A ){
                hash[c-'a']++;
                if(hash[c-'a'] > 1 ) return true;
            }
        }
        
        return false;
    }
};
