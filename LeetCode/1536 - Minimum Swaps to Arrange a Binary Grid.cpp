/*******************************************
 ***Problema: Minimum Swaps to Arrange a Binary Grid
 ***ID: 1536
 ***Juez: LeetCode
 ***Tipo: Suffix Counts + Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int minSwaps(vector<vector<int>>& grid) {        
        int n = grid.size(), res = 0;
        vector<int> arr(n);
        for( int i = 0 ; i < n ; ++i ){
            for( int j = n - 1 ; j >= 0  ; --j ){
                if( grid[i][j] == 0 )
                    arr[i]++;
                else
                    break;
            }
        }

        for( int i = 0, k = n - 1 ; i < n && k >= 1 ; ++i, --k ){
            int index = -1;
            for( int j = i ; j < n ; ++j ){
                if( arr[j] >= k ){
                    index = j;
                    break;
                }
            }
            if( index == -1 ){
                res = -1;
                break;
            }
            for( int j = index; j > i ; --j ){
                res++;
                swap(arr[j], arr[j - 1]);
            }
        }
        return res;
    }
};
