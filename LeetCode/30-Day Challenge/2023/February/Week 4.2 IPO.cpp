/*******************************************
 ***Problema: IPO
 ***ID: Week 4.2
 ***Juez: LeetCode
 ***Tipo: Priority queue + sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pii> v(n);        
        for(int i = 0 ; i < n ; ++i)
            v[i] = mp(capital[i], profits[i]);
        
        sort(v.begin(), v.end());
        priority_queue<int> Q;
        int i = 0;
        while(k > 0){
            while(i < n && v[i].first <= w){
                Q.push(v[i++].second);
            }
            if(Q.empty()) break;
            w += Q.top(); Q.pop();
            k--;
        }
        return w;
    }
};
