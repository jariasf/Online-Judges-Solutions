/*******************************************
 ***Problem: Build an Array With Stack Operations
 ***ID: 1441
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for( int i = 1, j = 0 ; i <= n && j < target.size() ; ++i ){
            res.push_back("Push");
            if( target[j] == i )
                j++;
            else
                res.push_back("Pop");
        }
        
        return res;
    }
};
