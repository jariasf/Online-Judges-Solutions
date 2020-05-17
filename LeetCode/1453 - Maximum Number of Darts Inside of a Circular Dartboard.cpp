/*******************************************
 ***Problema: Maximum Number of Darts Inside of a Circular Dartboard
 ***ID: 1453
 ***Juez: LeetCode
 ***Tipo: Geometry
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef double T;
    T dist(T x1, T y1, T x2, T y2){
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    
    T d(T x1, T y1, T x2, T y2){
        return 1.0*sqrt(dist(x1, y1, x2, y2));
    }    
    
    T D(T x1, T y1, T x2, T y2, T r){
        return sqrt(r * r - dist(x1, y1, x2, y2)/4.0 );
    }

    int countPoints(vector<vector<int> > &p, T cx, T cy, T r){
        int cnt = 0;
        for( int i = 0 ; i < p.size(); ++i ){
            T x = p[i][0], y = p[i][1];
            if( d(x, y, cx, cy) <= r ) cnt++;
        }
        return cnt;
    }
    
    int numPoints(vector<vector<int>>& p, int r) {
        int n = p.size();
        int maxi = 1;
        for( int i = 0 ; i < n ; ++i ){
            int x1 = p[i][0], y1 = p[i][1];
            for( int j = i + 1 ; j < n ; ++j ){
                T x2 = p[j][0], y2 = p[j][1];                
                T d_val = d(x1, y1, x2, y2);
                T D_val = D(x1, y1, x2, y2, r);
                T cx, cy;
                T xm = (x1 + x2)/2.0, ym = (y1 + y2)/2.0;
                //case 1
                cx = xm; cy= ym;    
                maxi = max(maxi, countPoints(p, cx, cy, r));

                //case 2, 3
                cx = xm + 2 * (D_val/d_val) * (y1 - ym); 
                cy = ym + 2 * (D_val/d_val) * (xm - x1);    
                maxi = max(maxi, countPoints(p, cx, cy, r));
                
                cx = xm - 2 * (D_val/d_val) * (y1 - ym); 
                cy = ym - 2 * (D_val/d_val) * (xm - x1);    
                maxi = max(maxi, countPoints(p, cx, cy, r));              
            }
        }
        return maxi;
    }
};
