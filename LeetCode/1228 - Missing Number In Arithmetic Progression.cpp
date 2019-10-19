/*******************************************
 ***Problema: Missing Number In Arithmetic Progression  
 ***ID: 1228
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int dif = (arr[n - 1] - arr[0])/n;
        int res = 0;
        for( int i = 1 ; i < n ; ++i ){
            if( arr[i] - arr[i - 1] != dif ){
                res = arr[i - 1] + dif;
                break;
            }
        }
        return res;
    }
};
