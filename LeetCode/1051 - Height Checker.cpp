/*******************************************
 ***Problema: Height Checker
 ***ID: 1051
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> aux(heights.begin(), heights.end());
        sort(aux.begin(), aux.end());
        int cnt = 0;
        for( int i = 0 ; i < heights.size(); ++i ){
            cnt += heights[i] != aux[i];
        }
        return cnt;
    }
};
