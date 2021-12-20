/*******************************************
 ***Problema: Adding Spaces to a String
 ***ID: 2109
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        string res = "";
        for( int i = 0, j = 0 ; i < s.size(); ++i ){
            if( j < spaces.size() && i == spaces[j]){
                res += " ";
                j++;
            }            
            res += s[i];
        }
        return res;
    }
};
