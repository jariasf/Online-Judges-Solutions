/*******************************************
 ***Problema: Moving Average from Data Stream
 ***ID: 642
 ***Juez: LintCode
 ***Tipo: Data Structures
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class MovingAverage {
public:
    double sum;
    int tot_size;
    deque<int> Q;
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        // do intialization if necessary
        sum = 0;
        tot_size = size;
        Q.clear();
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        if( Q.size() == tot_size ){
            sum -= Q.front();
            Q.pop_front();
        }
        Q.push_back(val);
        sum += val;
        return sum / (1.0 * Q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
