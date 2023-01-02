/*******************************************
 ***Problema: Detect Capital
 ***ID: Week 1.2
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt_upper{0}, upper_index{-1};
        for(int i = 0; i < word.size(); ++i){
            if(isupper(word[i])){
                cnt_upper++;
                upper_index = i;
            }
        }
        return (cnt_upper == word.size()) ||
               (cnt_upper == 0 || cnt_upper == 1 && upper_index == 0); 
    }
};
