/*******************************************
 ***Problema: The k Strongest Values in an Array
 ***ID: 1471
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int ,int>
    #define mp make_pair
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pii> v(n);

        sort(arr.begin(), arr.end());
        int m = arr[(n - 1)/2];
        for( int i = 0 ; i < n ; ++i )
            v[i] = mp( abs(arr[i] - m), arr[i] );
        
        sort(v.begin(), v.end());
        vector<int> res(k);
        for( int i = 0 ; i < k ; ++i )
            res[i] = v[ n - 1 - i ].second;
        
        return res;
    }
};
