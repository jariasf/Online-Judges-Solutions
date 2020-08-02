/*******************************************
 ***Problema: Get the Maximum Score
 ***ID: 1537
 ***Juez: LeetCode
 ***Tipo: Two Pointers | Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Time: O(n) Space: O(1)
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long LL;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        LL sum1 = 0, sum2 = 0, res = 0;
        int i = 0, j = 0;
        while( i < n1 && j < n2 ){
            if( nums1[i] < nums2[j] ){
                sum1 += nums1[i++];
            }else if( nums1[i] > nums2[j] ){
                sum2 += nums2[j++];
            }else{
                res += max(sum1, sum2) + nums1[i];
                sum1 = sum2 = 0;
                i++; j++;
            }
        }
        
        while( i < n1 ) sum1 += nums1[i++];
        while( j < n2 ) sum2 += nums2[j++];
        return (res + max(sum1, sum2)) % MOD;
    }
};


// Time: O(N) Space: O(N)
#define pii pair<int ,int>
#define mp make_pair
#define MAX 100005
typedef long long LL;
LL dp[MAX][3];
LL MOD = 1e9+7;
class Solution {
public:
    unordered_map<int, pii> hash;
    int n1, n2;
    vector<int> nums1, nums2;
    LL solve(int pos, bool a1){
        if( (a1 && pos == nums1.size()) || (!a1 && pos == nums2.size()) )
            return 0;
    
        if( dp[pos][a1] != -1 ) return dp[pos][a1];
        
        LL res = 0;
        if( a1 ){
            LL val = nums1[pos];
            pii p = hash[val];
            res = val + solve(pos + 1, a1);
            if(p.second != -1)
                res = max(res, val + solve(p.second + 1, !a1));
        }else{
            LL val = nums2[pos];
            pii p = hash[val];
            res = val + solve(pos + 1, a1);
            if(p.first != -1)
                res = max(res, val + solve(p.first + 1, !a1));            
        }
        
        return dp[pos][a1] = res;
    }
    
    
    int maxSum(vector<int>& _nums1, vector<int>& _nums2) {
        nums1 = _nums1; nums2 = _nums2;
        n1 = nums1.size(); n2 = nums2.size();
        hash.clear();
        for( int i = 0 ; i < n1 ; ++i )
            hash[nums1[i]] = mp(i, -1);
        
        for( int j = 0 ; j < n2 ; ++j ){
            if( hash.find(nums2[j]) == hash.end() ){
                hash[nums2[j]] = mp(-1, j);
            }else
                hash[nums2[j]].second = j;
        }
        
        memset( dp, -1, sizeof(dp));
        return max(solve(0, 0), solve(0, 1)) % MOD;
    }
};
