/*******************************************
 ***Problema: Verbal Arithmetic Puzzle
 ***ID: 1307
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 26
    vector<int> val;
    vector<int> used;
    vector<string> w;
    string target;
    vector<int> sum;
    bool solved;
    
    void solve(int i, int pos){    
        if( solved ) return;
        if( pos == target.size() ){
            if( sum[ pos - 1] == 0 ) return;
            solved = true;
            return;
        }
        
        if( i == w.size() ){
            int cur = target[pos] - 'A';
            int tmp = sum[pos];
            int carry = sum[pos]/10;
            int digit = sum[pos] % 10;
            
            if( val[cur] != -1 ){
                if( digit != val[cur] ){
                    return;
                }
            }
            
            if( used[digit] != -1 && used[digit] != cur ){
                return;
            }

            if( carry > 0 && pos + 1 == target.size() ) return;   
            
            sum[pos] = digit;
            if( carry > 0 ){
                sum[pos + 1] = carry;
            }
            
            int tmp_val = val[cur];
            if( val[cur] == -1 ){
                used[digit] = cur;
                val[cur] = digit;
            }
            
            solve(0, pos + 1);
            if( solved ) return;
            
            if( tmp_val  == -1 ){
                used[digit] = -1;
                val[cur] = -1;
            }
            
            if( carry > 0 ){
                sum[pos + 1] = 0;
            }
            sum[pos] = tmp;
            return;
        }
        
        if( pos < w[i].size() ){
            int cur = w[i][pos] - 'A';
            int start = 0;
            if( pos + 1 == w[i].size() ){
                start = 1;
            }

            if( val[cur] == -1 ){
                for( int j = start; j < 10 ; ++j ){
                    if( used[j] == -1 ){
                        used[j] = cur;
                        val[cur] = j;
                        sum[pos] += j;
                        solve(i + 1, pos);
                        if( solved ) return;
                        
                        sum[pos] -= j;
                        used[j] = -1;
                        val[cur] = -1;
                    }
                }
            }else{
                sum[pos] += val[cur];
                solve(i + 1, pos);
                if( solved ) return;
                
                sum[pos] -= val[cur];
            }
        }else if( pos >= w[i].size()){
            solve(i + 1, pos);
            if( solved ) return;
        }
        
    }    
    
    
    bool isSolvable(vector<string>& words, string result) {
        for( int i = 0 ; i < words.size(); ++i ){
            if( words[i].size() > result.size() ) return false;    
            reverse(words[i].begin(), words[i].end());
        }
        reverse(result.begin(), result.end());
        
        w = words;
        target = result;
        val = vector<int>(MAX, -1);
        used = vector<int>(10, -1);
        sum = vector<int>(result.size(), 0);
        solved = false;
        solve(0, 0);
        return solved;
    }
};
