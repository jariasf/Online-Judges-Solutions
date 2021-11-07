/*******************************************
 ***Problema: Minimized Maximum of Products Distributed to Any Store
 ***ID: 2064
 ***Juez: LeetCode
 ***Tipo: Binary Search the Answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool possible(int n, vector<int> &v, LL maxi){
        int sz = v.size();
        for( int i = 0 ; i < sz ; ++i ){
            int div = v[i]/maxi;
            int rem = v[i] % maxi;
            int cnt = div + (rem > 0);
            n -= cnt;
            if( n < 0 ) return false;
        }
        return n >= 0;
        
    }
    int minimizedMaximum(int n, vector<int>& v) { 
        int sz = v.size();
        int left = 1, right = 0;
        for( int i = 0 ; i < sz ; ++i ) right = max(right, v[i]);
        right++;
        int res = 0;
        while( left < right ){
            LL mid = (left + right)/2;
            if( possible(n, v, mid) ){
                right = mid;
                res = mid;
            }else{
                left = mid + 1;
            }
        }
        return res;
    }
};
