/*******************************************
 ***Problema: Largest Merge Of Two Strings
 ***ID: 1754
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string largestMerge(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        string res = "";
        int i = 0 , j = 0;
        while( i < n1 && j < n2 ){
            if( s1[i] > s2[j] || (s1[i] == s2[j] && s1.substr(i) > s2.substr(j)) ){
                res += s1[i++];
            }else{
                res += s2[j++];
            }
        }
        while(i < n1 ) res += s1[i++];
        while(j < n2 ) res += s2[j++];
        return res;
    }
};
