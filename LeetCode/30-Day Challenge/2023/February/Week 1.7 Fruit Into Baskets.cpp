/*******************************************
 ***Problema: Fruit Into Baskets
 ***ID: Week 1.7
 ***Juez: LeetCode
 ***Tipo: Sliding window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), cnt1, cnt2, key1, key2, res;
        cnt1 = cnt2 = res = 0;
        key1 = key2 = -1;
        for(int right = 0, left = 0 ; right < n ; ++right){
            while( cnt1 != 0 && cnt2 != 0 && fruits[right] != key1 && fruits[right] != key2){
                if( fruits[left] == key1 ) cnt1--;
                else cnt2--;
                left++;
            }
            res = max(res, right - left + 1);
            if( cnt1 == 0 || fruits[right] == key1){
                key1 = fruits[right];
                cnt1++;
            }else{
                key2 = fruits[right];
                cnt2++;
            }
        }
        return res;
    }
};
