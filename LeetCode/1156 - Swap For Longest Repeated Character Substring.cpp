/*******************************************
 ***Problema: Swap For Longest Repeated Character Substring
 ***ID: 1156
 ***Juez: LeetCode
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 30
    
    bool exist(int pos, int val, vector<vector<int> > &sum, int n ){
        if( pos - 2 >= 0  ){
            if( sum[val][pos - 1] > 0 ) return true;    
        }
        if( pos + 2 < n ){
            if( sum[val][n] - sum[val][pos + 2 ] > 0 ) return true;
        }        
        return false;
    }
    #define pii pair<int,int>
    #define mp make_pair
    
    int maxRepOpt1(string text) {
        int n = text.size();

        vector<pii> v;
        for( int i = 0 ; i < n; ++i ){
            int j = i + 1;
            int cnt = 1;
            while( j < n && text[i] == text[j] ){
                j++;
                cnt++;
            }
            v.push_back( mp(text[i] - 'a', cnt) );
            i = j - 1;
        }
        
        n = v.size();
        if( n == 1 ){
            return v[0].second;    
        }
        
        vector<vector<int> > sum(MAX, vector<int>(n + 5));
        
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 0 ; j < MAX; ++j ){
                if( v[i - 1].first == j ){
                    sum[j][i] = sum[j][i - 1] + v[i - 1].second;
                }else{
                    sum[j][i] = sum[j][i - 1];
                }
            }            
        }
        
        int result = 0;
        for( int i = 0 ; i < n ; ++i ){
            int left = -1, right = -1;
            if( i > 0 ) left = v[i - 1].first;
            if( i + 1 < n ) right = v[i + 1].first;
            result = max( result, v[i].second);
            if( exist(i, v[i].first, sum, n) ){
                result = max( result, v[i].second + 1);        
            }

            if( left != -1 ){
                if( exist(i, left, sum, n) ){
                    result = max( result, v[i - 1].second + 1 );
                }
            } 
         
            if( right != -1 ){
                if( exist(i, right, sum, n) ){
                    result = max( result, v[i + 1].second + 1 );
                }
            }
            
            if( left == right && left != -1 && v[i].second == 1 ){
                if( exist(i, left, sum , n) ){
                    result = max( result, v[i - 1].second + v[i + 1].second + 1);
                }
                result = max( result, v[i - 1].second + v[i + 1].second);
            }
        }
        
        return result;
    }
};
