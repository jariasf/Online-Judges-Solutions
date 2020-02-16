/*******************************************
 ***Problem: Construct Target Array With Multiple Sums
 ***ID: 1354
 ***Judge: LeetCode
 ***Type: Priority Queue
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    bool isPossible(vector<int>& target) {
        int n = target.size();
        
        LL tot = 0;
        priority_queue<int> Q;        
        for( int i = 0 ; i < n ; ++i ){
            tot += target[i];
            Q.push(target[i]);
        }
        
        while( !Q.empty() ){
            LL cur = Q.top(); Q.pop();
            if( cur == 1 ) break;
            LL s = tot - cur;
            if( cur > s ){
                if( s == 0 ) return false;
                int rem = cur % s;
                if( rem >= 1 ){
                    tot -= cur;
                    Q.push(rem);
                    tot += rem;
                }else if( s == 1 ){
                    return true;
                }else
                    return false;
            }else
                return false;
        }

        return true;
    }
};
