/*******************************************
 ***Problema: Maximum Profit in Job Scheduling
 ***ID: 1235
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming + Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    struct Interval{
        int start, end, profit;
        Interval(int s, int e, int p){
            start = s; end = e; profit = p;
        }
        bool operator<(Interval &t2 ){
            return end < t2.end;
        }
        Interval(){}
    };
    
    vector<Interval> interval;
    int lower_bound(Interval &cur, int n){
        int left = 1, right = n;
        while( left < right ){
            int mid = left + (right - left)/2;
            Interval next = interval[mid - 1];
            if( next.end <= cur.start ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left - 1;
    }    
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        interval = vector<Interval>(n);
        for(int i = 0 ; i < n ; ++i )
            interval[i] = Interval(startTime[i], endTime[i], profit[i]);
        sort(interval.begin(), interval.end());
        
        vector<int> dp(n + 5, 0);
        for( int i = 1 ; i <= n ; ++i ){
            Interval cur = interval[i - 1];
            int lower = lower_bound(cur, i);
            Interval left = interval[lower];
            dp[i] = max(dp[i], cur.profit + dp[lower] );
            dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[n];
    }
};
/*
[4,2,4,8,2]
[5,5,5,10,8]
[1,2,8,10,4]
out: 18
*/
