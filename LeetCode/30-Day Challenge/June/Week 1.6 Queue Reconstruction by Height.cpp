/*******************************************
 ***Problema: Queue Reconstruction by Height
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    class cmp {
        public:
        bool operator() (vector<int> &p1, vector<int> &p2) { 
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1] );
        }
    } cmp;    
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort( people.begin(), people.end() , cmp );
        int n = people.size();
        vector<vector<int> > result;
        for( int i = 0 ; i < n ; ++i ){
            result.insert(result.begin() + people[i][1] , people[i]);
        }
        return result;        
    }
};
