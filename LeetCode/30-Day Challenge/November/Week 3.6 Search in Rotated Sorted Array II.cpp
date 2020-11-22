/*******************************************
 ***Problema: Search in Rotated Sorted Array II
 ***ID: Week3.6
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool search(vector<int>& num, int target) {
        int n = num.size();
        int left = 0, right = n - 1, mid;
        while( left <= right ){
            mid = (left + right)>>1;
            
            if( num[mid] == target ) return true;
            
            if( num[right]  == num[left]) left++;
            else if( num[mid] > target ){
                if( num[mid] <= num[right] || num[left] <= target  ){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if( num[mid] >= num[left] || num[right] >= target ){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
