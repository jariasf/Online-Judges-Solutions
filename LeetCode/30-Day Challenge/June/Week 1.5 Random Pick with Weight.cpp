/*******************************************
 ***Problema: Random Pick with Weight
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Sampling from discrete distribution
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<double> prob; 
    Solution(vector<int>& w) {
        srand (time(NULL));
        int n = w.size();
        prob = vector<double>(n);
        double cur = 0, tot = 0;
        for( int i = 0 ; i < n ; ++i )
            tot += w[i];
        
        for( int i = 0 ; i < n; ++i ){
            cur += w[i]/tot;
            prob[i] = cur;
        }
    }
    
	// O(log(n))
    int pickIndex() {
        double p = double(rand()) / (double(RAND_MAX) + 1.0);
        int left = 0, right = prob.size();
        while( left < right ){
            int mid = ( left + right )/2;
            if( prob[mid] <= p){
                left = mid + 1;
            }else
                right = mid;
        }
        return left;
    }
    
    // O(n)
    int pickIndex2() {
        double p = double(rand()) / (double(RAND_MAX) + 1.0);
        double cur = 0;
        int last_index = 0;
        for( int i = 0 ; i < prob.size(); ++i ){
            cur = prob[i];
            if( cur > p ){
                last_index = i;                
                break;
            }
        }
        return last_index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
