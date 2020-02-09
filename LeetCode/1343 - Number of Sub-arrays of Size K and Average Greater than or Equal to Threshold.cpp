/*******************************************
 ***Problema: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 ***ID: 1343
 ***Juez: LeetCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if( n < k ) return 0;
        int t = threshold * k;
        int cnt = 0, sum = 0;
        for( int i = 0 ; i < k ; ++i )
            sum += arr[i];
        if( sum >= t ) cnt++;
        for( int i = k ; i < n ; ++i ){
            sum -= arr[i - k];
            sum += arr[i];
            if( sum >= t ){
                cnt++;
            }
        }
        return cnt;
    }
};
