/*******************************************
 ***Problema: Merge Intervals
 ***ID: 156
 ***Juez: LintCode
 ***Tipo: Sorting
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

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */

    static bool cmp(Interval &a, Interval &b){
        return a.start < b.start;
    } 

    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        vector<Interval> result;
        if( n == 0 ) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval last = intervals[0];
        for(int i = 1 ; i < n ; ++i ){
            if( intervals[i].start <= last.end ){
                last.end = max(last.end, intervals[i].end);
            }else{
                result.push_back(last);
                last = intervals[i];
            }
        }
        result.push_back(last);
        return result;
    }
};
