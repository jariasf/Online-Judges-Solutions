/*******************************************
 ***Problema: Random Point in Non-overlapping Rectangles
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: Prefix Sums + Uniform Sampling + Map
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//pick O(log num_rectangles)
class Solution {
public:
    vector<vector<int> > r;
    int n;
    map<int, int> areas;
    Solution(vector<vector<int>>& rects) {
        r = rects;
        n = 0;
        areas.clear();
        for( int i = 0 ; i < rects.size() ; ++i ){
            int x1 = r[i][0], y1 = r[i][1];
            int x2 = r[i][2], y2 = r[i][3];
            int h = x2 - x1 + 1, w = y2 - y1 + 1, area = h * w;
            n += area;
            areas[n] = i;
        }
    }
    
    vector<int> pick() {
        int index = rand() % n;
        auto it = areas.upper_bound(index);
        int rec_index = it -> second;
        index = it -> first - index - 1;
        int x1 = r[rec_index][0], y1 = r[rec_index][1];
        int x2 = r[rec_index][2], y2 = r[rec_index][3];
        int h = x2 - x1 + 1, w = y2 - y1 + 1;
        int x = index/w, y = index % w;
        return {x1 + x, y1 + y};
    }
};

//pick O(num_rectangles)
class Solution {
public:
    vector<vector<int> > r;
    int n;
    vector<int> areas;
    Solution(vector<vector<int>>& rects) {
        r = rects;
        n = 0;
        areas.clear();
        for( int i = 0 ; i < rects.size() ; ++i ){
            int x1 = r[i][0], y1 = r[i][1];
            int x2 = r[i][2], y2 = r[i][3];
            int h = x2 - x1 + 1, w = y2 - y1 + 1, area = h * w;
            n += area;
            areas.push_back(area);
        }
    }
    
    vector<int> pick() {
        int index = rand() % n;
        int rec_index = -1;
        for( int i = 0 ; i < areas.size(); ++i ){
            if( index + 1 > areas[i] ){
                index -= areas[i];
            }else{
                rec_index = i;
                break;
            }
        }
        
        int x1 = r[rec_index][0], y1 = r[rec_index][1];
        int x2 = r[rec_index][2], y2 = r[rec_index][3];
        int h = x2 - x1 + 1, w = y2 - y1 + 1;
        int x = index/w, y = index % w;
        return {x1 + x, y1 + y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
