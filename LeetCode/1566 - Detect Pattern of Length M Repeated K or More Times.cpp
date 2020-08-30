/*******************************************
 ***Problema: Detect Pattern of Length M Repeated K or More Times
 ***ID: 1566
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i ; j < n ; ++j ){
                int len = j - i + 1;
                if( len == m ){
                    int cnt = 1;
                    for( int k = j + 1, ii = i, l = 0; k < n ; ++k ){
                        if( arr[k] != arr[ii] ){
                            break;
                        }
                        if(l + 1 == len ){
                            l = 0;
                            cnt++;
                            ii = i;
                        }else{
                            l++;
                            ii++;
                        }
                    }
                    if( cnt == k ) return true;
                }
            }
        }
        return false;
    }
};
