/*******************************************
 ***Problema: Prison Cells After N Days
 ***ID: 957
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int toInt(vector<int>& cells){
        int n = cells.size();
        int val = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( cells[i] == 1 ){
                val |= 1<<i;
            }
        }
        return val;
    }
    
    vector<int> toCell(int x){
        vector<int> cell(8);
        for( int i = 0 ; i < 8 ; ++i ){
            if( x & (1<<i) ){
                cell[i] = 1;
            }
        }
        return cell;
    }
    
    int nextState(int x){
        vector<int> cell;       
        cell = toCell(x);
        vector<int> aux( cell.begin(), cell.end() );
        for( int i = 0 ; i < 8 ; ++i ){
            if( i == 0 || i == 7 ){
                aux[i] = 0;
            }else{
                if( cell[i - 1] == cell[i + 1] ) aux[i] = 1;
                else aux[i] = 0;
            }
        }
        return toInt(aux);
    }

    void print(int x){
        vector<int> cell;       
        cell = toCell(x);
        for( int i = 0 ; i < 8 ; ++i ) cout<<cell[i]<<" ";
        cout<<endl;
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int n = cells.size();
        int origin = toInt(cells);
        vector<bool> seen(1<<9, 0);
        vector<int> path;
        bool first = true;
        int curr = origin;
        while( !seen[curr] && path.size() <= N ){
            if( !first ){
                path.push_back(curr);
                seen[curr] = true;
            }
            first = false;

            curr = nextState(curr);
        }

        int sz = path.size();
        if( sz == 0 ) return cells;
        if( N % sz == 0 ){
            return toCell(path[sz - 1]);
        }
        return toCell(path[ N % sz - 1]);
    }
};
