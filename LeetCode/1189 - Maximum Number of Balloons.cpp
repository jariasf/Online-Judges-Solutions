/*******************************************
 ***Problema: Maximum Number of Balloons
 ***ID: 1189
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> cnt(26);
        for( int i = 0 ; i < n ; ++i ){
            cnt[ text[i] - 'a' ]++;
        }
        
        cnt['l' - 'a'] /= 2;
        cnt['o' - 'a'] /= 2;
        
        string obj = "balloon";
        int minimum = cnt['b'-'a'];
        for( int i = 0 ; i <  obj.size(); ++i ){
            minimum = min( minimum, cnt[obj[i] - 'a']);
        }
        return minimum;
    }
};
