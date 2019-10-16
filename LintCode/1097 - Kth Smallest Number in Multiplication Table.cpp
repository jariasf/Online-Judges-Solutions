/*******************************************
 ***Problema: Kth Smallest Number in Multiplication Table
 ***ID: 1097
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countSmallest(int x, int m, int n){
        int cnt = 0;
        for( int i = 1 ; i <= n ; ++i )
            cnt += min(m, x/i);
        return cnt;
    } 
     
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = n * m, mid;
        while( left <= right ){
            mid = (left + right)/2;
            int cnt = countSmallest(mid, m, n);
            if( cnt < k ){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};
