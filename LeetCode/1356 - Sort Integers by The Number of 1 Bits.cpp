/*******************************************
 ***Problem: Sort Integers by The Number of 1 Bits
 ***ID: 1356
 ***Judge: LeetCode
 ***Type: Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    struct comp{
        int getOnes(int x){
            int cnt = 0;
            while(x){
                x = x & (x - 1);
                cnt++;
            }
            return cnt;
        }        
        bool operator()(int &a, int &b){
            int oa = getOnes(a);
            int ob = getOnes(b);
            return oa < ob || (oa == ob && a < b);
        }
    }cmp;
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
