/*******************************************
 ***Problema: Exam Room
 ***ID: 855
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class ExamRoom {
public:
    set<int> hash;
    int n;
    ExamRoom(int N) {
        n = N;
        hash.clear();
    }
    
    int seat() {
        if( hash.size() == 0 ){
            hash.insert(0);
            return 0;
        }
        
        int left = 0, right = n - 1;
        vector<int> v(hash.begin(), hash.end());
        if( v.size() == 1 ){
            int dl = v[0] + left;
            int dr = right - v[0];
            if( dr > dl ){
                hash.insert(right);
                return right;
            }else{
                hash.insert(left);
                return left;
            }
            
        }else{
            int maxi = -1, value = -1;
            if( v[0] != 0 ){
                maxi = v[0];
                value = 0;
            }
            
            if( v[v.size() - 1] != right ){
                v.push_back(right + 1);
            }
            
            for( int i = 0 ; i < v.size() - 1 ; ++i ){
                int pos = (v[i + 1] + v[i])/2;
                int dist = min( abs(pos - v[i]) , abs(v[i + 1] - pos) );
                if( dist > maxi ){
                    maxi = dist;
                    value = pos;
                }
            }
                        
            if( maxi != -1 ){
                hash.insert(value);
                return value;
            }
        }
        
    }
    
    void leave(int p) {
        if( hash.find(p) != hash.end() ) hash.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
