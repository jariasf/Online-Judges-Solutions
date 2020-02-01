/*******************************************
 ***Problema: Find K Pairs with Smallest Sums
 ***ID: 373
 ***Juez: LeetCode
 ***Tipo: Priority Queue | MultiSet
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
     
    struct State{
        int i, sum;
        State(int _i, int _sum){
            i = _i;
            sum = _sum;
        }
        bool operator<( const State &s2) const {
            return sum > s2.sum || (sum == s2.sum && i > s2.i); //returns ordered pairs
        }
    };
     
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        priority_queue<State> Q;
        
        int n = nums1.size(), m = nums2.size();
        
        vector<vector<int> > res;
        if( n == 0 || m == 0 )
            return res;

        for( int j = 0 ; j < m ; ++j ){
            Q.push(State(0, nums1[0] + nums2[j]));
        }
    
        while(k-- > 0 && !Q.empty()){
            State cur = Q.top(); Q.pop();
            int n1 = nums1[cur.i], n2 = cur.sum - n1;
            res.push_back({n1, n2});
            int next_i = cur.i + 1;
            if( next_i < n ){
                Q.push(State(next_i, nums1[next_i] + n2));
            }
        }

        return res;
    }
};
