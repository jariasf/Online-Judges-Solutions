/*******************************************
 ***Problema: Smallest Sufficient Team 
 ***ID: 1125
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming, Bitmasks, Minimum Vertex Cover
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 80
    vector<int> seen;
    vector<string> skills;
    vector<vector<string> > p;
    
    int bitcount( int n ){
        int cnt = 0;
        while( n ){
            n = n & ( n - 1 );
            cnt++;
        }
        return cnt;
    }
    
    int dp[1<<16 + 1][17];
    
    int solve(int mask, int pos){
        
        if( bitcount(mask) == skills.size() ){
            return dp[mask][pos] = 0;
        }
        
        if( mask & (1<<pos) ){
            return dp[mask][pos] = solve( mask, pos + 1);
        }
        
        if( dp[mask][pos] != -1 ) return dp[mask][pos];
        
        int res = 1<<30;
        for(int i = 0 ; i < p.size(); ++i ){
            for( int j = 0 ; j < p[i].size(); ++j ){
                if( p[i][j] == skills[pos] ){
                    res = min( res, 1 + solve( mask | seen[i], pos + 1) );
                }
            }
        }
        return dp[mask][pos] = res;
    }
    
    vector<int> result;
    void recover(int mask, int pos, int mini){
        if( bitcount(mask) == skills.size() ){
            return;
        }

        if( (mask & (1<<pos)) && mini == dp[mask][pos + 1] ){
            recover(mask, pos + 1, mini);
            return;
        }        
        
        bool finished = false;
        for(int i = 0 ; i < p.size() && !finished; ++i ){
            for( int j = 0 ; j < p[i].size() && !finished; ++j ){
                if( p[i][j] == skills[pos] && 1 + dp[mask | seen[i]][pos + 1] == mini ){
                    result.push_back(i);
                    recover( mask | seen[i], pos + 1, mini - 1);
                    finished = true;
                }
            }
        }

        
    }
    
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        seen = vector<int>( people.size() );
        for( int i = 0 ; i < req_skills.size(); ++i ){
            for( int j = 0 ; j < people.size(); ++j ){
                for( int k = 0 ; k < people[j].size(); ++k ){
                    if( people[j][k] == req_skills[i] ){
                        seen[j] |= 1<<i;
                        break;
                    }
                }
            }
        }
        memset( dp, -1, sizeof(dp));
        skills = req_skills;
        p = people;
        
        int mini = solve(0, 0);
        result.clear();
        recover(0, 0, mini);
        return result;
        
    }
};
