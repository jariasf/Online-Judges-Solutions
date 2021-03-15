/*******************************************
 ***Problema: Trapping Rain Water
 ***ID: 363
 ***Juez: LintCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int left = 0, right = heights.size() - 1, result = 0, max_left = 0, max_right = 0;
        while( left <= right ){
            max_left = max(max_left, heights[left]);
            max_right = max(max_right, heights[right]);
            if( max_left < max_right)
                result += max_left - heights[left];
            else
                result += max_right - heights[right];
            
            if( heights[left] < heights[right] )
                left++;
            else
                right--;

        }
        return result;
    }
};
