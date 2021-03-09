/*******************************************
 ***Problema: Kth Smallest Element in a Specific Array
 ***ID: 1874
 ***Juez: LintCode
 ***Tipo: Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param arr: an array of integers
     * @param k: an integer
     * @return: the Kth smallest element in a specific array
     */
    struct Node {
        int val, row, col;
        Node(){

        }
        Node(int _val, int _row, int _col){
            val = _val; row = _row; col = _col;
        }

        bool operator < ( const Node &other ) const {
            return val > other.val;
        }
    };


    int kthSmallest(vector<vector<int>> &a, int k) {
        int num_rows = a.size(), res = -1;
        priority_queue<Node> Q;

        for(int i = 0 ; i < a.size() ; ++i ){
            if( a[i].size() > 0 ) 
                Q.push(Node(a[i][0],i,0));
        }

        while( k > 0 && !Q.empty() ){        
            Node cur = Q.top(); Q.pop();
            res = cur.val;
            cur.col++;
            if( cur.col < a[cur.row].size() ){
                cur.val = a[cur.row][cur.col];
                Q.push(cur);
            }
            k--;
        }
        return res;
    }
};
