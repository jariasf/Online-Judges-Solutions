/*******************************************
 ***Problema: Find in Mountain Array
 ***ID: 1095
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    
    int findPeakElement(MountainArray &nums) {
        int n = nums.length();
        int left = 0, right = n;
   	 	while(left < right){
       		int mid = (left + right)/2;
       		int next = -INT_MAX;
       		if( mid + 1 < n ) next = nums.get(mid + 1);
       		int last = -INT_MAX;
       		if( mid - 1 < n ) last = nums.get(mid - 1);
            int aux = nums.get(mid);
       		if( aux >= next && aux >= last ) return mid;
       		if( aux >= last ) left = mid + 1;
       		else right = mid;
   		}
   		return left;
    }    
    
    int findInMountainArray(int target, MountainArray &v) {
        int index = findPeakElement(v);
        if( target == v.get(index) ) return index;
        int left = 0, right = index;
        while( left < right){
            int mid = ( left + right )/2;
            int val = v.get(mid);
            if( val == target ) return mid;
            if( val < target ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        
        left = index + 1; right = v.length();
        while( left < right ){
            int mid = ( left + right )/2;
            int val = v.get(mid);
            if( val == target ) return mid;
            if( val > target ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return -1;
    }
};
