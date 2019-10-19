/*******************************************
 ***Problema: Divide Chocolate
 ***ID: 1231
 ***Juez: LeetCode
 ***Tipo: Binary Search The Answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int simulate(vector<int> &sweetness, int K, int maxi ){
        int n = sweetness.size();
        int sum = 0, mini = 1<<30;
        for( int i = 0 ; i < n ; ++i ){
            sum += sweetness[i];
            if( sum >= maxi ){
                K--;
                mini = min(mini, sum);
                sum = 0;
            }
        }
        if( K > 0 )
            return -1;
        return mini;
    }
    
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int n = sweetness.size();
        int right = 0;
        for( int i = 0 ; i < n ; ++i ){
            right += sweetness[i];
        }
        int left = 0;
        right++;
        int res = 0;
        while( left < right ){
            int mid = left + (right - left)/2;
            int my_sweetness = simulate(sweetness, K + 1, mid);
            if( my_sweetness == mid ){
                res = mid;
            }
            if( my_sweetness >= mid ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return res;
    }
};
