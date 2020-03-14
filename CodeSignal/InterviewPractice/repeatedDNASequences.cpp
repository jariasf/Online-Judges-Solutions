/*******************************************
 ***Problem: Repeated DNA Sequences
 ***Judge: CodeSignal
 ***Typr: Hashing + Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        if(n < 10) return res;

        unordered_map<string, int> hash;
        string cur = "";
        for( int i = 0 ; i < 10; ++i)
            cur += s[i];

        hash[cur]++;
        for( int i = 10 ; i < n; ++i ){
            cur += s[i];
            cur.erase(0, 1);
            hash[cur]++;
        }
        for(auto it: hash){
            if( it.second > 1 ) 
                res.push_back(it.first);
        }

        sort(res.begin(), res.end());
        return res;
    }
};
