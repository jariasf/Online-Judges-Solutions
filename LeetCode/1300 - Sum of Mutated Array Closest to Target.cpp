/*******************************************
 ***Problema: Sum of Mutated Array Closest to Target
 ***ID: 1300
 ***Juez: LeetCode
 ***Tipo: Binary Search The Answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int simulate(vector<int> &arr, int val, int target){
        int sum = 0;
        for( int i = 0 ; i < arr.size(); ++i ){
            if( arr[i] >= val ) sum += val;
            else sum += arr[i];
        }
        return sum;
    }
   
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = target;
        for( int i = 0 ;  i < n ; ++i ) right = max(right, arr[i]);
        int res = -1, aux = 1<<30;
        while( left < right ){
            int mid = (left + right)/2;
            int val = simulate(arr, mid, target);
            int dif = abs(target - val);
            if( dif < aux ){
                aux = dif;
                res = mid;
            }else if( dif == aux ){
                res = min( res, mid );
            }
            if( val < target ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return res;
    }
};
