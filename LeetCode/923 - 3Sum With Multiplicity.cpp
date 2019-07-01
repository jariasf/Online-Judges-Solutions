/*******************************************
 ***Problema: 3Sum With Multiplicity
 ***ID: 923
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MOD 1000000007
#define pii pair<int,int>
#define mp make_pair
typedef long long LL;
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        LL result = 0;
        vector<pii> v;
        int n = A.size();        
        for( int i = 0 ; i < n ; ++i )
            v.push_back(mp(A[i], i));
        
        sort( v.begin(), v.end() );
        for( int i = 0 ; i < n ; ++i ){
            int a = v[i].first;
            int index_i = v[i].second;
            int toFind = target - a;
            int left = i + 1;
            int right = n - 1;
            while( left < right ){
                int b_index = v[left].second;
                int b = v[left].first;
                int c = v[right].first;
                int c_index = v[right].second;
                if( b + c == toFind ){
                    if( b == c ){
                        LL cnt = right - left + 1;
                        result = result + cnt * ( cnt - 1 )/2;
                        result %= MOD;
                        break;
                    }else{
                        LL cnt_left = 1; left++;
                        while( left <= right && v[left].first == b ){
                            left++;
                            cnt_left++;
                        }

                        LL cnt_right = 1; right--;
                        while( left <= right && v[right].first == c ){
                            right--;
                            cnt_right++;
                        }
                        result = result + cnt_left * cnt_right;
                        result %= MOD;
                    }
                }else if( b + c > toFind ){
                    right--;
                }else{
                    left++;
                }
            }
        }

        return result;
    }
};
