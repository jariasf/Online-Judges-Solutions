/*******************************************
 ***Problem: Constrained Subset Sum
 ***ID: 1425
 ***Judge: LeetCode
 ***Type: Deque
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pii> Q;
        int n = nums.size();
        int maxi = -(1<<30);
        for( int i = 0 ; i < n ; ++i ){
            while( !Q.empty() && Q.front().second < i - k ){
                Q.pop_front();
            }
            if( !Q.empty() ){
                pii cur = Q.front();
                int sum = cur.first + nums[i];
                if( sum < nums[i] ){
                    sum = nums[i];    
                }
                
                maxi = max(maxi, sum);
                while( !Q.empty() && sum >= Q.back().first ){
                    Q.pop_back();
                }
                Q.push_back(mp(sum, i));
            }else{
                Q.push_back( mp(nums[i], i) );
                maxi = max(maxi, nums[i]);
            }
        }
        return maxi;
    }
};
