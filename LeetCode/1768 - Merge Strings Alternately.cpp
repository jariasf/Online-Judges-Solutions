/*******************************************
 ***Problema: Merge Strings Alternately
 ***ID: 1768
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int i = 0 , j = 0, n = s1.size(), m = s2.size();
        string res = "";
        while(i < n && j < m ){
            res += s1[i++];
            res += s2[j++];
        }
        while(i < n) res += s1[i++];
        while(j < m) res += s2[j++];
        return res;
    }
};
