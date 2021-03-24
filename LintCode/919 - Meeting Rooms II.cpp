/*******************************************
 ***Problema: Meeting Rooms II
 ***ID: 919
 ***Juez: LintCode
 ***Tipo: Ad hoc, prefix-sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// O(nlogn)
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */

    static bool cmp(Interval &a, Interval &b){
        return a.start < b.start;
    } 

    bool intersect(Interval &a, Interval &b){
        return b.start < a.end;
    }
    
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size(), result = 0;
        sort(intervals.begin(), intervals.end(), cmp );
        priority_queue<int, vector<int>, greater<int> > Q;
        for(Interval cur: intervals){
            Q.push(cur.end);
            if(cur.start < Q.top()){
                result++;
            }else
                Q.pop();
        }
        return result;
    }
};


//O(n^2)
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */

    static bool cmp(Interval &a, Interval &b){
        return a.start < b.start;
    } 

    bool intersect(Interval &a, Interval &b){
        return b.start < a.end;
    }

    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp );
        vector<bool> used(n, false);
        int result = 0;
        for(int i = 0 ; i < n ; ++i){
            if( used[i]) continue;
            result++;
            Interval current = intervals[i];
            used[i] = true;
            for( int j = i + 1 ; j < n ; ++j ){
                if( !used[j] && !intersect(current, intervals[j]) ){
                    used[j] = true;
                    current.end = intervals[j].end;
                }
            }
        }
        return result;
    }
};
