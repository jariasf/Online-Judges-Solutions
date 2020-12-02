/*******************************************
 ***Problema: Sliding Window Maximum
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Sliding Window + Deque
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        if( n == 0 ) return result;
        if( k == 1 ) return nums;
        deque<pii> Q;
        for( int i = 0 ; i < k ; ++i ){
            while( !Q.empty() && Q.back().first < nums[i] ){
                Q.pop_back();
            }
            Q.push_back( mp(nums[i],i));
        }

        result.push_back(Q.front().first);
        for( int i = k, left = 0 ; i < n ; ++i, ++left ){ 
            if( !Q.empty() && Q.front().second == left ) Q.pop_front();
            while( !Q.empty() && Q.back().first < nums[i] ){
                Q.pop_back();
            }
            Q.push_back( mp(nums[i],i));
            
            result.push_back(Q.front().first);
        }
        return result;
    }
};
