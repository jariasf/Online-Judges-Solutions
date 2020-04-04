/*******************************************
 ***Problem: Circle and Rectangle Overlapping
 ***ID: 1401
 ***Judge: LeetCode
 ***Type: Geometry
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool checkOverlap(int radius, int cx, int cy, int x1, int y1, int x2, int y2) {
        int rw = x2 - x1, rh = y2 - y1;
        double rx = x1 + rw/2.0, ry = y1 + rh/2.0;
        double dx = fabs(cx - rx);
        double dy = fabs(cy - ry);
        if( (dx > rw/2.0 + radius) | (dy > rh/2.0 + radius) ) return false;
        if( (dx <= rw/2.0) || (dy <= rh/2.0 ) ) return true;
        double d_sq = (dx - rw/2.0) * (dx - rw/2.0) + (dy - rh/2.0) * (dy - rh/2.0);
        return d_sq <= radius * radius;
    }
};
