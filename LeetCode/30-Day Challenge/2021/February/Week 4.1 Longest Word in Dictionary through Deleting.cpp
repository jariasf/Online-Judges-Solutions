/*******************************************
 ***Problema: Longest Word in Dictionary through Deleting
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: Brute Force + Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool subsequence(string &s, string &q){
        int i = 0, j = 0, n = s.size(), m = q.size();
        if(n < m ) return false;
        while(i < n && j < m ){
            if( s[i] == q[j] ){
                i++; j++;
            }else
                i++;
        }
        return j == m;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        int n = s.size(), m = d.size();
        string res = "";
        for( int i = 0 ; i < m ; ++i ){
            string cur = d[i];
            if( subsequence(s, cur) ){
                if( res.size() < cur.size() )
                    res = cur;
                else if( res.size() == cur.size() && res > cur ){
                    res = cur;
                }
            }
        }
        return res;
    }
};
