/*******************************************
 ***Problema: Special Array With X Elements Greater Than or Equal X
 ***ID: 1608
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        for( int i = 0; i <= nums.size() ; ++i ){
            int cnt = 0;
            for(int val:nums){
                if( val >= i ) 
					cnt++;
            }
            if( cnt == i ) return i;
        }
        return -1;
    }
};
