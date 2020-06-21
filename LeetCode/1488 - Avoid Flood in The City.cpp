/*******************************************
 ***Problema: Avoid Flood in The City
 ***ID: 1488
 ***Juez: LeetCode
 ***Tipo: Hashing + Set
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> zero;
        int n = rains.size();
        unordered_map<int, int> hash;
        vector<int> res(n, -1);
        for( int i = 0 ; i < n ; ++i ){
            int cur = rains[i];
            if( cur == 0 ){
                zero.insert(i);
                continue;
            }
            if( hash.find(cur) == hash.end() ){
                hash[cur] = i;
                res[i] = -1;
            }else{
                int last_pos = hash[cur];
                auto it = zero.lower_bound(last_pos + 1);
                if( it != zero.end() ){
                    res[*it] = cur;
                    hash[cur] = i;
                    zero.erase(it);
                }else{
                    return {};
                }
            }
        }
        for(auto it:zero ){
            res[it] = 1;
        }
        return res;
    }
};
