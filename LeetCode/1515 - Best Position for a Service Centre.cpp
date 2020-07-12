/*******************************************
 ***Problema: Best Position for a Service Centre
 ***ID: 1515
 ***Juez: LeetCode
 ***Tipo: Geometric Median - Simulated Annealing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};    
    
    double dist(double x1, double x2, double y1, double y2){
        return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
    }
    
    double dist_sum(double x, double y, vector<vector<int> > &p ){
        double sum = 0;
        for( int i = 0 ; i < p.size(); ++i ){
            sum += dist(p[i][0], x, p[i][1], y);
        }
        return sum;
    }
    
    double getMinDistSum(vector<vector<int>>& p) {
        double best = dist_sum(p[0][0], p[0][1], p);
        int n = p.size();
        double x = 0, y = 0;
        for( int i = 0 ; i < n; ++i ){
            x += p[i][0];
            y += p[i][1];
        }   
        x /= (double)(n);
        y /= (double)(n); 
        
        double mini = dist_sum(x, y, p);
        double step = 50; 
        double eps = 0.000001;
        bool b = 0; 
        while( step > eps){ 
            b = 0; 
            for (int i = 0; i < 4; ++i) { 
                double new_x = x + step * dx[i];
                double new_y = y + step * dy[i];
                double cur_dist = dist_sum(new_x, new_y, p); 
                if(cur_dist < mini) { 
                    mini = cur_dist; 
                    x = new_x; 
                    y = new_y; 
                    b = 1; 
                    break; 
                } 
            } 
            
            if(!b) 
                step /= 2.0; 
        } 
        return mini;        
    }

};
