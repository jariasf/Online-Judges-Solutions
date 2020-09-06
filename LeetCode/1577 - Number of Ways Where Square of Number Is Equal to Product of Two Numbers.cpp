/*******************************************
 ***Problema: Number of Ways Where Square of Number Is Equal to Product of Two Numbers
 ***ID: 1577
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

typedef long long LL;
class Solution {
public:
    int countTriplets(LL val, vector<int>& v){
        unordered_map<int,int> hash;        
        int res = 0;
        for(int cur: v){
            if( val % cur == 0 )
                res += hash[val/cur];
            hash[cur]++;
        }
        return res;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for( LL val: nums1 ) res += countTriplets(val * val, nums2);
        for( LL val: nums2 ) res += countTriplets(val * val, nums1);        
        return res;
    }
};
