/*******************************************
 ***Problema: Replace Elements with Greatest Element on Right Side
 ***ID: 1299
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        int maxi = arr[n - 1];
        for( int i = n - 2 ; i >= 0 ; --i ){
            res[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        return res;
    }
};
