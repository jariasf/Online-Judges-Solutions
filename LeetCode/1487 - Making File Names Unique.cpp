/*******************************************
 ***Problema: Making File Names Unique
 ***ID: 1487
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n = names.size();
        vector<string> res (n);
        unordered_map<string, int> cnt;
        string s;
        for( int i = 0; i < n ; ++i ){            
            s = names[i];
            if( cnt.find(s) == cnt.end() ){
                res[i] = s;
                cnt[s] = 1;
            }else{
                int k = cnt[s];
                do{
                    s = names[i] +  "(" + to_string(k++) + ")";
                }while( cnt.find(s) != cnt.end() );
                cnt[names[i]] = k;
                cnt[names[i] + "(" + to_string(k - 1) + ")"] = 1;
                res[i] = s;
            }
        }
        return res;
    }
};
