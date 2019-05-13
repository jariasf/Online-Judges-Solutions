/*******************************************
 ***Problema: Longest Turbulent Subarray
 ***ID: 978
 ***Juez: LeetCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        int result = 0;
        for( int i = 0 ; i < n - 1 ; ++i ){
            bool incr = false;
            if( A[i] == A[i + 1]) continue;
            if( A[i] > A[i + 1] ){
                incr = true;
            }
            int cnt = 1;
            int j = i + 1;
            while( j < n - 1 ){
                if( incr ){
                    if( A[j] < A[j + 1] ){
                        cnt++;
                        j++;
                        incr = !incr;
                    }else{
                        break;
                    }
                }else{
                    if( A[j] > A[j + 1]){
                        cnt++;
                        j++;
                        incr = !incr;
                    }else{
                        break;
                    }
                }
            }
            i = j - 1;
            result = max(result, cnt);
        }
        return result + 1;
    }
};
