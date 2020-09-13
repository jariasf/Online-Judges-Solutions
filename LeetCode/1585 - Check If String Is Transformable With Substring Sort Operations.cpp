/*******************************************
 ***Problema: Check If String Is Transformable With Substring Sort Operations
 ***ID: 1585
 ***Juez: LeetCode
 ***Tipo: Deque
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isTransformable(string s, string t) {
        deque<int> Q[10];
        int n = s.size();
        for( int i = 0 ; i < n ; ++i )
            Q[s[i] - '0'].push_back(i);
        
        for( int i = 0 ; i < n ; ++i ){
            int val = t[i] - '0';
            if( Q[val].empty() ) return false;
            int pos = Q[val].front();
            Q[val].pop_front();
            for( int j = 0 ; j < val ; ++j )
                if( !Q[j].empty() && Q[j].front() < pos ) 
                    return false;
        }
        return true;
    }
};
