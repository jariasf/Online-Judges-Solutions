/*******************************************
 ***Problema: Form Array by Concatenating Subarrays of Another Array
 ***ID: 1764
 ***Juez: LeetCode
 ***Tipo: Ad hoc - KMP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int m = nums.size(), n = groups.size(), pos = 0;
        for( int i = 0 ; i < m && pos != n ; ++i ){
            if( i + groups[pos].size() > m ) break;
            bool b = true;
            for( int j = 0 ; j < groups[pos].size() ; ++j ){
                if( groups[pos][j] != nums[i + j] ){
                    b = false;
                    break;
                }
            }
            if(b){ i += groups[pos++].size() - 1;}
        }
        return pos == n;
    }
};
