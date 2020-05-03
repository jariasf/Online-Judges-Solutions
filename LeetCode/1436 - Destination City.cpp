/*******************************************
 ***Problem: Destination City
 ***ID: 1436
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, int> hash;
        unordered_set<string> s;
        for( int i = 0 ; i < n ; ++i ){
            string u = paths[i][0], v = paths[i][1];
            hash[u] = 1;
            s.insert(u);
            s.insert(v);
        }
        
        for(auto v:s ){
            if( hash[v] == 0 ) return v;
        }
        return "";
    }
};
