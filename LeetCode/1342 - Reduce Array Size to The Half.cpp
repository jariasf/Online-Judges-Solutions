/*******************************************
 ***Problema: Reduce Array Size to The Half
 ***ID: 1342
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> cnt;
        for( int i = 0 ; i < n ; ++i ){
            cnt[ arr[i] ]++;
        }
        
        vector<int> v;
        for(auto &it: cnt){
            v.push_back(it.second);
        }
        
        sort(v.rbegin(), v.rend());
        
        int result = 0, sz = n;
        for( int i = 0 ; i < v.size(); ++i ){
            sz -= v[i];
            result++;
            if( sz * 2 <= n ) break;
        }
        return result;
    }
};
