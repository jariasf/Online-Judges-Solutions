/*******************************************
 ***Problema: Strange Printer II
 ***ID: 1591
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Uncover blocks in reverse order
#define MAX 62
class Solution {
public:
    bool isPrintable(vector<vector<int>>& v) {
        int h = v.size(), w = v[0].size();
        vector<int> seen(MAX, false), colors;
        vector<vector<int> > maxi(MAX, vector<int>({-1,-1})), mini(MAX,vector<int>({MAX, MAX}));

        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                int c = v[i][j];
                if( !seen[c] ){
                    seen[c] = 1;
                    colors.push_back(c);
                }
                maxi[c][0] = max(maxi[c][0], i);
                maxi[c][1] = max(maxi[c][1], j);       
                mini[c][0] = min(mini[c][0], i);
                mini[c][1] = min(mini[c][1], j);
            }
        }
            
        int n = colors.size();
        while(true){
            bool correct = false;
            int cnt = 0;
            for( int k = 0; k < n ; ++k ){
                int c = colors[k];
                if( c < 0 ){ 
                    cnt++;
                    continue;
                }
                bool top = true;
                for( int i = mini[c][0]; i <= maxi[c][0]; ++i ){
                    for( int j = mini[c][1]; j <= maxi[c][1]; ++j ){
                        if( v[i][j] && v[i][j] != c ){
                            top = false;
                            goto end;
                        }
                    }
                }
                end:
                if( top ){
                    for( int i = mini[c][0]; i <= maxi[c][0]; ++i ){
                        for( int j = mini[c][1]; j <= maxi[c][1]; ++j ){
                            v[i][j] = 0;
                        }
                    }
                    colors[k] = -1;
                    correct = true;
                    break;
                }
            }
            if( cnt == n ) break;            
            if( !correct ){
                return 0;
            }
        }
        return 1;
    }
};
