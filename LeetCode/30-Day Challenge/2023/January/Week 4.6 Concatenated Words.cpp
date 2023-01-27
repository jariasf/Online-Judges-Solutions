/*******************************************
 ***Problema: Concatenated Words
 ***ID: Week 4.6
 ***Juez: LeetCode
 ***Tipo: Recursion
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/


// O(n*l + n*l^3)

class Solution {
public:

    unordered_set<string> hash;

    bool possible(string &s, int pos, int cnt){
        int n = s.size();
        if( pos == n ){
            return cnt > 1;
        }
        string str="";
        for(int i = pos ; i < n; ++i){
            str += s[i];
            if( hash.count(str) && (possible(s, i + 1, cnt + 1)) ) return true;
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string w: words) hash.insert(w);
        vector<string> res;
        for(string w:words){
            if(possible(w, 0, 0)){
                res.push_back(w);
            }
        }
        return res;
    }
};
