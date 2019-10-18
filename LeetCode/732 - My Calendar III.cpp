/*******************************************
 ***Problema: My Calendar III
 ***ID: 732
 ***Juez: LeetCode
 ***Tipo: Segment Tree | BST
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// BST
class MyCalendarThree {
public:
    map<int ,int> hash;
    MyCalendarThree() {
        hash.clear();
    }
    
    int book(int start, int end) {
        hash[start]++;
        hash[end]--;
        int maximum = 0, sum = 0;
        for(auto it:hash ){
            sum += it.second;
            maximum = max(maximum, sum );
        }
        return maximum;
    }
};


// Segment Tree using pointers
class SegmentTree{
public:    
    
    struct TreeNode{
        int start, end, val, lazy, maxi;
        TreeNode* left, *right;
        TreeNode(int s, int e){
            val = lazy = maxi = 0;
            left = right = NULL;
            start = s; end = e;
        }
        TreeNode(){
            val = lazy = maxi = start = end = 0;
            left = right = NULL;
        }
    };

    int maximum;
    TreeNode* tree;
    
    SegmentTree(int s, int e){
        tree = new TreeNode(s, e);
        maximum = 0;
    }
    SegmentTree(){}
    
    void update(int from, int to, int value){
        return update(tree, from, to, value);
    }
    
    void update(TreeNode* tree, int from, int to, int value){
        int left = tree -> start, right = tree -> end;
        if( to >= right && from <= left){
            tree -> val += value;
            tree -> lazy = 1; //lazy propagation
            tree -> maxi += value;
            maximum = max(maximum, tree -> maxi);
            return;
        }
        
        int mid = left + (right - left)/2;
        if( tree -> left == NULL ) tree -> left = new TreeNode(left, mid);
        if( tree -> right == NULL ) tree -> right = new TreeNode(mid + 1, right);
        
        if( tree->lazy == 1){
            tree->left->lazy = tree->right->lazy = 1;
            tree->left->val += tree->val;
            tree->right->val += tree->val;
            tree->left->maxi += tree->val;
            tree->right->maxi += tree->val;
            
            tree->lazy = 0;
            tree->val = 0;
            tree->maxi = 0;
        }
        
        if( from <= mid )
            update(tree -> left, from, to, value);            
        if( to > mid )
            update(tree -> right, from, to, value);
        
        tree -> maxi = max(tree->left->maxi, tree->right->maxi);
        maximum = max(maximum, tree->maxi);
    }    
};

class MyCalendarThree {
public:
    SegmentTree tree;
    MyCalendarThree() {
        tree = SegmentTree(0, 1e9 + 5);
    }
    
    int book(int start, int end) {
        end--;
        tree.update(start, end, 1);
        return tree.maximum;
    }
};



// Segment Tree using hashmap
class SegmentTree{
public:    
    struct State{
        int val, lazy, maxi;
        State(int v, int l, int m){
            val = v;
            lazy = l;
            maxi = m;
        }
        State(){
            val = lazy = maxi = 0;
        }
    };
    
    unordered_map<int, State > tree;
    int maximum;
    SegmentTree(){
        tree.clear();
        maximum = 0;
    }
    
    void update(int from, int to, int value, int left=0, int right=1e9 + 5, int node=0){
        if( to >= right && from <= left){
            tree[node].val += value;
            tree[node].lazy = 1; //lazy propagation
            tree[node].maxi += value;
            maximum = max(maximum, tree[node].maxi);
            return;
        }
        int mid = left + (right - left)/2, L = 2 * node + 1, R = 2 * node + 2;
        
        if( tree[node].lazy == 1){
            tree[L].lazy = tree[R].lazy = 1;
            tree[L].val += tree[node].val;
            tree[R].val += tree[node].val;
            tree[L].maxi += tree[node].val;
            tree[R].maxi += tree[node].val;
            
            tree[node].lazy = 0;
            tree[node].val = 0;
            tree[node].maxi = 0;
        }
        
        if( from <= mid )
            update(from, to, value, left, mid, L);            
        if( to > mid )
            update(from, to, value, mid + 1, right, R);
        
        tree[node].maxi = max(tree[L].maxi, tree[R].maxi);
        maximum = max(maximum, tree[node].maxi);
    }
};

class MyCalendarThree {
public:
    SegmentTree tree;
    MyCalendarThree() {
        tree = SegmentTree();
    }
    
    int book(int start, int end) {
        end--;
        tree.update(start, end, 1);
        return tree.maximum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
