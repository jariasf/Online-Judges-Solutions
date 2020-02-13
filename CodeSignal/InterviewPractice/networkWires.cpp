/*******************************************
 ***Problema: Network Wires
 ***Juez: CodeSignal
 ***Tipo: Minimum Spanning Tree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class UnionFind{
public:
    vector<int> uf;
    UnionFind(int n){
        uf = vector<int>(n);
        for( int i = 0 ; i < n ; ++i )
            uf[i] = i;
    }    
    
    int Find(int x){
        if( x == uf[x] ) return x;
        return uf[x] = Find(uf[x]);
    }
    
    void Union(int x, int y){
        uf[Find(x)] = Find(y);
    }
    
    bool sameComponent(int x, int y){
        return Find(x) == Find(y);
    }
};

struct comp{
    bool operator()(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }
}cmp;

int networkWires(int n, std::vector<std::vector<int>> wires) {
    UnionFind uf = UnionFind(n);
    sort(wires.begin(), wires.end(), cmp);
    int total = 0;
    for(int i = 0 ; i < wires.size(); ++i ){
        int u = wires[i][0], v = wires[i][1], w = wires[i][2];
        if( !uf.sameComponent(u, v) ){
            uf.Union(u, v);
            total += w;
        }
    }
    return total;
}
