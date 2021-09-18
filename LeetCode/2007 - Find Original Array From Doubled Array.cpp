/*******************************************
 ***Problema: Find Original Array From Doubled Array
 ***ID: 2007
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> res;
        if( n & 1 ) return res;
        sort(changed.begin(), changed.end());
        vector<int> hash(100005);
        for( int v: changed) hash[v]++;
        int maxi = changed[n - 1];
        for( int i = 0 ; i < n ; ++i ){
            if( hash[changed[i]] == 0 ) continue;
            hash[changed[i]]--;
            int next = changed[i] * 2;
            if( next <= maxi && hash[next] > 0 ){
                hash[next]--;
                res.push_back(changed[i]);
            }
        }
        if( res.size() != n/2 ) return {};
        return res;
    }
};
