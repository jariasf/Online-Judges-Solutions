/*******************************************
 ***Problema: Subarrays with K Different Integers
 ***ID: 992
 ***Juez: LeetCode
 ***Tipo: Hashing - Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> hash;
        int right = 0, k = 0, result = 0;
        int equals = 0;
        for( int left = 0; left < n ; ++left ){
            bool inserted = false;
            while( right < n && k < K ){
                hash[ A[right]]++;
                if( hash[ A[right]] == 1 ) k++;
                right++;
                inserted = true;
            }

            if( k == K ){
                if( inserted ){
                    equals = 0;
                    int j = right;
                    while( j < n && hash.find(A[j]) != hash.end() ){
                        j++;
                        equals++;
                    }
                }
                result += equals + 1;
            }
            
            hash[ A[left] ]--;
            if( hash[ A[left] ] == 0 ){
                k--;
                hash.erase(A[left]);
            }
            
        }
        return result;
    }
};
