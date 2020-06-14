/*******************************************
 ***Problema: Minimum Number of Days to Make m Bouquets
 ***ID: 1482
 ***Juez: LeetCode
 ***Tipo: Binary Search The Answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    bool simulate(vector<int> &v, int m, int k, int maxi){
        int cnt = 0;
        for( int i = 0 ; i < v.size(); ++i ){
            if( v[i] <= maxi ){
                if( i - 1 >= 0 && v[i - 1] <= maxi ){
                    cnt++;
                }else{
                    cnt = 1;
                }
            }else{
                m -= cnt/k;
                cnt = 0;
            }
        }
        m -= cnt/k;
        return m <= 0;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if( m * k > n ) return -1; 
        int left = 0, right = 1<<30;
        while(left < right){
            int mid = (left + right)/2;
            if( !simulate(bloomDay, m, k, mid) ){
                left = mid + 1;
            }else
                right = mid;
            
        }
        return left;
    }
};
