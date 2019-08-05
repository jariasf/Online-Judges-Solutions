/*******************************************
 ***Problema: Meeting Rooms
 ***ID: 920
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
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
     
    struct{
        bool operator()(Interval &t1, Interval &t2) {
            return t1.start < t2.start || (t1.start == t2.start && t1.end < t2.end);
        }
    }comp;
     
    bool intersect(Interval &t1, Interval &t2 ){
        return (t1.start <= t2.start && t2.start < t1.end) ||
               (t1.start < t2.end && t2.end <= t1.end );
    } 
     
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        for( int i = 1 ; i < intervals.size(); ++i ){
            if( intersect(intervals[i - 1], intervals[i]) )
                return false;
        }
        return true;
    }
};
