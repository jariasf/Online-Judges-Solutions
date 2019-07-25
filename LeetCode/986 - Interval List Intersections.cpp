/*******************************************
 ***Problema: Interval List Intersections
 ***ID: 986
 ***Juez: LeetCode
 ***Tipo: Merge Intervals
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int> > result;
        vector<int> interval(2);
        int index_A = 0, index_B = 0;
        
        while( index_A < A.size() && index_B < B.size() ){
            int minimum = min( A[index_A][1] , B[index_B][1] );
            int maximum = max( A[index_A][0] , B[index_B][0] );
            if( maximum <= minimum ){
                interval[0] = maximum;
                interval[1] = minimum;
                result.push_back( interval );
            }
            
            if( minimum == A[index_A][1] ){
                index_A++;
            }
            if( minimum == B[index_B][1] ){
                index_B++;
            }
        }
        
        return result;
    }
};
