/*******************************************
 ***Problema: Design Browser History
 ***ID: 1472
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class BrowserHistory {
public:
    int size, cur;
    vector<string> v;
    BrowserHistory(string homepage) {
        size = 1;
        v.clear();
        v.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        if( cur + 1 == v.size() )
            v.push_back(url);
        else
            v[cur + 1] = url;

        cur++;
        size = cur + 1;
    }
    
    string back(int steps) {
        int mini = min(steps, cur);
        cur -= mini;
        return v[cur];
    }
    
    string forward(int steps) {
        int mini = min(size - 1, cur + steps);
        cur = mini;
        return v[cur];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
