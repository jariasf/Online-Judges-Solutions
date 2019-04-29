/************************************************************
 ***Problema: Partition Array Into Three Parts With Equal Sum
 ***ID: 1013
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************************/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        int n = A.size();
        for( int i = 0 ; i < n ; ++i ) sum += A[i];
        if( sum % 3 != 0 ) return false;
        int cnt = 0;
        int val = sum/3;
        for( int i = 0 ; i < n ; ++i ){
            int j = i + 1;
            int aux = A[i];
            if( cnt == 3 ){
                while( j < n ){
                    aux += A[j];
                    j++;
                } 
                if( aux != 0 ) return false;
                return true;
            }
            while( j < n && aux != val ){
                aux += A[j];
                j++;
            }            
            if( aux != val ) return false;
            cnt++;
            i = j - 1;
        }
        return true;
    }
};
