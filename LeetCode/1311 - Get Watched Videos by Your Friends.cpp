/*******************************************
 ***Problema: Get Watched Videos by Your Friends
 ***ID: 1311
 ***Juez: LeetCode
 ***Tipo: BFS + Hashing + Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> bfs(vector<vector<int>>& friends, int id){
        int n = friends.size();
        vector<int> dist(n, 1<<30);
        queue<int> Q;
        Q.push(id);
        dist[id] = 0;
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for( int i = 0 ; i < friends[cur].size() ; ++i ){
                int v = friends[cur][i];
                if( dist[cur] + 1 < dist[v]){
                    dist[v] = dist[cur] + 1;
                    Q.push(v);
                }
            }
        }
        return dist;
    }
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> dist = bfs(friends, id);
        int n = dist.size();
        unordered_map<string, int> hash;

        for( int i = 0 ; i < n ; ++i ){
            if( dist[i] == level){
                for( int j = 0 ; j < watchedVideos[i].size(); ++j ){
                    hash[watchedVideos[i][j]]++;
                }
            }
        }
        
        vector<pair<int, string> > tmp;
        for(auto it:hash ){
            tmp.push_back( make_pair(it.second, it.first) );
        }
        sort(tmp.begin(), tmp.end());

        vector<string> res;
        for( int i = 0 ; i < tmp.size(); ++i ){
            res.push_back( tmp[i].second);
        }
        return res;
    }
};
