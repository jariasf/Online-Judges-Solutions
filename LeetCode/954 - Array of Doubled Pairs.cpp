/*******************************************
 ***Problema: Array of Doubled Pairs
 ***ID: 954
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        unordered_map<int, int> used;
        unordered_map<int, int> hash;
        for( int i = 0 ; i < n ; ++i ){
            hash[A[i]]++;
            used[A[i]] = 0;
        }
        
        for( int i = 0 ; i < n ; ++i ){
            if( used[A[i]] > 0 ){
                used[A[i]]--;
                continue;
            }
            if( hash[2 * A[i]] > 0 ){
                hash[2 * A[i]]--;
                used[2 * A[i]]++;
                hash[A[i]]--;
            }else if( A[i] % 2 == 0 && hash[A[i]/2] > 0 ){
                hash[ A[i]/2 ]--;
                used[ A[i]/2 ]++;
                hash[A[i]]--;
            }else
                return false;
        }
        
        return true;
    }
};
