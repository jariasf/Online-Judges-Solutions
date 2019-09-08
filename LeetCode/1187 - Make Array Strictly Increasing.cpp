/*******************************************
 ***Problema: Make Array Strictly Increasing
 ***ID: 1187
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<vector<int> > > dp;
    vector<int> v1, v2;
    int solve(int i, int j, bool replaced){
        
        if( i == v1.size() ){
            return 0;
        }
        if( j == v2.size() ) return 1<<30;
        
        if( j >= 0 && dp[i][j][replaced] != -1 ) return dp[i][j][replaced];
        
        int res = 1<<30;
        if(replaced){    
            if( v1[i] > v2[j]){
                res = solve(i + 1, j , 0);
            }
            int jj = j + 1;
            while(jj < v2.size() ){
                if( v2[j] < v2[jj] ){
                    res = min( res, 1 + solve( i + 1, jj , 1 ));
                    break;
                }
                jj++;
            }
        }else{
            if( i == 0 || ( i - 1 >= 0 && v1[i] > v1[i - 1])){
                res = solve(i + 1, j , 0);
            }
            
            int jj = j + 1;
            while(jj < v2.size() ){
                if(i == 0 || (i - 1 >= 0 && v1[i - 1] < v2[jj]) ){
                    res = min( res, 1 + solve( i + 1, jj , 1 ));
                    break;
                }
                jj++;
            }
        }
        if( j < 0 ) return res;
        return dp[i][j][replaced] = res;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        v1 = arr1; v2 = arr2;
        dp.clear();
        dp = vector<vector<vector<int> > >( v1.size() + 1, vector<vector<int> > (v2.size() + 1, vector<int>(2, -1)));
        int res= solve(0, -1, 0);
        if( res == 1<<30 ) return -1;
        return res;
    }
};
