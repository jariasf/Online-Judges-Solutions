/*******************************************
 ***Problema: Maximum Ice Cream Bars
 ***ID: Week 1.6
 ***Juez: LeetCode
 ***Tipo: Greedy – Sorting | Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Sorting
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for(int v: costs){
            if( coins < v ) break;
            coins -=v;
            res++;
        }
        return res;
    }
};


// Hashing
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0;
        int maxi = *max_element(costs.begin(), costs.end());
        int mini = *min_element(costs.begin(), costs.end());
        vector<int> hash(maxi + 1);
        for(int v:costs) hash[v]++;
        for(int cost = mini ; cost <= maxi ; ++cost){
            if(hash[cost] == 0) continue;
            int min_coins = min(coins/hash[cost], hash[cost]);
            hash[cost] -= min_coins;
            res += min_coins;
        }
        return res;
    }
};
