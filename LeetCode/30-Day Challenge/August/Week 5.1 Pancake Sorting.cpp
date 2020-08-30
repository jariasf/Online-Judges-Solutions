/*******************************************
 ***Problema: Pancake Sorting
 ***ID: Week5.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> res;
        while(n > 0){
            int maxi = 0, index = -1;
            for( int i = 0 ; i < n ; ++i ){
                if( A[i] > maxi ){
                    maxi = A[i];
                    index = i;
                }
            }

            if( index + 1 != maxi ){
                if( index > 0 ){
                    res.push_back(index + 1);
                    reverse(A.begin(), A.begin() + index + 1);
                }
                    
                if(n > 1){
                    res.push_back(n);
                    reverse(A.begin(), A.begin() + n);
                }
            }
            n--;
        }
        return res;
    }
};
