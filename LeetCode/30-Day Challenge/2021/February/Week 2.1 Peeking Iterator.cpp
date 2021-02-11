/*******************************************
 ***Problema: Peeking Iterator
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    bool calledPeek;
    int lastValue;

	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    calledPeek = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if( calledPeek ){
            return lastValue;
        }
        calledPeek = true;
        lastValue = Iterator::next();
        return lastValue;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if( calledPeek ){
	        calledPeek = false;
	        return lastValue;
	    }
	    return Iterator::next();
	}

	bool hasNext() const {
	    if( calledPeek ){
	        return true;
	    }
	    return Iterator::hasNext();
	}
};
