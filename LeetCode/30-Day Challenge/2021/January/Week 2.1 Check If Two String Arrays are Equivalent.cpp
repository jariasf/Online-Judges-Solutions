/*******************************************
 ***Problema: Check If Two String Arrays are Equivalent
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "", b = "";
        for(string s1:word1) a += s1;
        for(string s2:word2) b += s2;
        return a == b;
    }
};
