/*******************************************
 ***Problema: Design A Leaderboard
 ***ID: 1244
 ***Juez: LeetCode
 ***Tipo: Data Structures
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Leaderboard {
public:
    map<int, int, greater<int> > scores;
    unordered_map<int, int> cnt;
    
    Leaderboard() {
        cnt.clear();
        scores.clear();
    }
    
    void decrease(int score){
        if( scores.find(score) == scores.end() ) return;
        scores[score]--;
        if( scores[score] == 0 ){
            scores.erase(score);
        }
    }

    void addScore(int playerId, int score) {
        int cur = cnt[playerId];
        decrease(cur);
        cnt[playerId] += score;
        scores[cnt[playerId]]++;
    }
    
    int top(int K) {
        int total = 0;
        for(auto it:scores){
            int players = it.second;
            int score = it.first;
            int mini = min( players, K );
            total += score * mini;
            K -= mini;
            if( K == 0 ) break; 
        }
        return total;
    }
    
    void reset(int playerId) {
        int score = cnt[playerId];
        decrease(score);
        cnt[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
