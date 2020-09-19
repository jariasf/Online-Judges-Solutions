/*******************************************
 ***Problema: Sum of All Odd Length Subarrays
 ***ID: 1588
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), res = 0;
        for( int i = 0 ; i < n; ++i ){
            int sum = 0 ;
            for( int j = i, k = 1 ; j < n ; ++j, ++k){
                sum += arr[j];
                if( k & 1){
                    res += sum;
                }
            }
        }
        return res;
    }
};
