/*******************************************
 ***Problema: Next Permutation
 ***ID: 31
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Iterative
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void nextPermutation(vector<int>& num) {
        int n = num.size();
        int pivot = -1;
        for( int i = n - 2 ; i >= 0 ; --i ){
            if( num[i] < num[i + 1]){
                pivot = i;
                break;
            }
        }
        
        if( pivot != -1 ){
            int next_pivot = pivot + 1;
            for( int i = pivot + 1 ; i < n ; ++i ){
                if( num[pivot] < num[i] && num[next_pivot] >= num[i] ){
                    next_pivot = i;
                }
            }
            swap(num[next_pivot], num[pivot]);
        }
        
        reverse(num.begin() + pivot + 1, num.end() );
    }
};
