/*******************************************
 ***Problema: Container With Most Water
 ***ID: Week3.3
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int left = 0, right = sz - 1;
        int ans = 0;
        while( left < right ){
            ans = max(ans, min( height[left], height[right]) * ( right - left ));
            if( height[left] < height[right] )
                left++;
            else
                right--;
        }
        return ans;
    }
};
