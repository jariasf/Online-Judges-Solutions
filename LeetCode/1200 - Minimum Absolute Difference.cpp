/*******************************************
 ***Problema: Minimum Absolute Difference
 ***ID: 1200
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int dif = abs(arr[1] - arr[0]);
        
        for( int i = 2 ; i <  n ; ++i ){
            dif = min( dif, abs(arr[i] - arr[i - 1]));
        }
        
        vector<vector<int> > res;
        for( int i = 1 ; i < n; ++i ){
            if( arr[i] - arr[i - 1] == dif ){
                vector<int> v = {arr[i - 1], arr[i]};
                res.push_back(v);
            }
        }
        return res;
    }
};
