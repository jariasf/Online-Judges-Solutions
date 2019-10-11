/*******************************************
 ***Problema: Perfect Rectangle
 ***ID: 1264
 ***Juez: LintCode
 ***Tipo: Hashing + Counting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    /**
     * @param rectangles: N axis-aligned rectangles
     * @return: if they all together form an exact cover of a rectangular region
     */
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first * 10) ^ hash<int>()(p.second);
        }
    };
    
    int bitcount(int n){
        int ones = 0;
        while(n){
            n = n & (n - 1);
            ones++;
        }
        return ones;
    } 
    
    bool isRectangleCover(vector<vector<int>> &rectangles) {
       unordered_map<pair<int,int> , int, PairHash> hash;
       int xmin, xmax, ymin, ymax;
       xmin = ymin = 1<<30;
       xmax = ymax = -(1<<30);
       int subarea = 0;
       for( int i = 0 ; i < rectangles.size(); ++i ){
            vector<int> rectangle = rectangles[i];
            // updating mask of each coordinate
            vector<pair<int,int> > coordinates = { make_pair(rectangle[0], rectangle[1]), 
                                                   make_pair(rectangle[2], rectangle[1]), 
                                                   make_pair(rectangle[2], rectangle[3]),
                                                   make_pair(rectangle[0], rectangle[3])};
            for(int j = 0 ; j < coordinates.size(); ++j ){
                pair<int,int> key = coordinates[j];
                int mask = hash[key];
                if( mask & (1<<j) ) return false;
                hash[key] = mask | (1<<j);
            }
            // subarea
            subarea += ( rectangle[2] - rectangle[0] ) * (rectangle[3] - rectangle[1]);
            
            // total area
            xmax = max(xmax, max(rectangle[0], rectangle[2]));
            xmin = min(xmin, min(rectangle[0], rectangle[2]));
            ymax = max(ymax, max(rectangle[1], rectangle[3]));
            ymin = min(ymin, min(rectangle[1], rectangle[3]));
       }
       
       int corner_mask = 0;
       for(auto it:hash){
           int value = it.second;
           int bits = bitcount(value);
           if( bits == 1 ){ // corner
               if( corner_mask & value ) return false;
               corner_mask |= value;
           }else if( bits & 1 ) // empty area
               return false;
       }
       
       if( corner_mask != (1<<4) - 1 ) return false;
       return subarea == (xmax - xmin) * (ymax - ymin);
    }   
};
