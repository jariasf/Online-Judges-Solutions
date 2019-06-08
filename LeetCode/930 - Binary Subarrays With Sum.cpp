/*******************************************
 ***Problema: Binary Subarrays With Sum
 ***ID: 930
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        unordered_map<int,int> cnt;
        int sum = 0;
        int result = 0;
        cnt[0] = 1;
        for( int i = 0 ; i < n ; ++i ){
            sum += A[i];
            if( cnt.find( sum - S ) != cnt.end() )
                result += cnt[ sum - S ];
            cnt[sum]++;
        }
        return result;
    }
};
