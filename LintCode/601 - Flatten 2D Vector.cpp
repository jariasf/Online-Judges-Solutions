/*******************************************
 ***Problema: Flatten 2D Vector
 ***ID: 601
 ***Juez: LintCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Vector2D {
public:
    vector<vector<int> > vec;
    int row, col;
    Vector2D(vector<vector<int>>& vec2d) {
        vec = vec2d;
        row = 0; col = 0;
    }

    int next(){
        return vec[row][col++];
    }

    bool hasNext(){
        while(row < vec.size() ){
            if( col < vec[row].size() ) return true;
            else{
                col = 0; row++;
            }
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
