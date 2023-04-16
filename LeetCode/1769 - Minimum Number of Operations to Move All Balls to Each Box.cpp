/*******************************************
 ***Problema: Minimum Number of Operations to Move All Balls to Each Box
 ***ID: 1769
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// O(n)



// O(n^2)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < i ; ++j ){
                if( boxes[j] == '1'){
                    res[i] += (i - j);
                }
            }
            for( int j = i + 1 ; j < n ; ++j ){
                if( boxes[j] == '1'){
                    res[i] += (j - i);
                }
            }            
        }
        return res;
    }
};
