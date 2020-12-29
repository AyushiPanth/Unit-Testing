// Range => [low, high)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Range {
	protected: 
	    int low;
	    int high;
	
	public:
	    Range() {
	    	this->low = 0;
		    this->high = 0;
	    }

	    Range(int end) {
		    this->low = 0;
		    this->high = end;
	    }

	    Range(int first, int second) {
	    	this->low = min(first, second);
		    this->high = max(first, second) - 1;
	    }

	    void reset() {
		    this->low = 0;
		    this->high = 0;
    	}

	    void rightStretch() {
		    this->high++;
	    }

	    void rightStretch(int size) {
		    this->high += size;
    	}

    	void leftStretch() {
	    	this->low--;
    	}

    	void leftStretch(int size) {
	    	this->low -= size;
	    }

	    void stretch() {
    		this->low--;
    		this->high++;
    	}

    	void stretch(int size) {
    		this->low -= size;
    		this->high += size;
    	}

    	void squeeze() {
		    this->low++;
		    this->high--;
		    if(this->low > this->high)
		    	this->reset();
    	}

    	void squeeze(int size) {
    		this->low += size;
    		this->high -= size;
    		if(this->low > this->high)
    			this->reset();
    	}
    	
    	void shift(int shifter) {
    		this->low += shifter;
    		this->high += shifter;
    	}
    
    	int length() {
    		return this->high - this->low + 1;
    	}
    	
    	string toString() {
    		return "[" + to_string(this->low) + "," + to_string(this->high + 1) + ")";
    	}
    
    	bool contains(int element) {
    		return this->low <= element && element <= this->high;
    	}
    
    	bool contains(Range r) {
    		return this->low <= r.low && this->high >= r.high;
    	}
    
    	bool equals(Range r) {
    		return r.low == this->low && r.high == this->high; 
    	}
    
    	bool disjoint(Range r) {
    		return r.low > this->high || r.high < this->low; 
    	}
    
    	bool overlap(Range r) {
    		return !(this->disjoint(r));
    	}
    
    	bool lessThan(Range r) {
    		return this->low < r.low;
    	}
    
    	bool greaterThan(Range r) {
    		return this->low > r.low;
    	}
    
    	bool touching(Range r) {
    		return r.low == this->low || r.high == this->high;
    	}
    	
    	Range merge(Range r) {
    		if(disjoint(r))
    			return Range();
    		return Range(min(low, r.low), max(high, r.high));
    	}
    	
    	Range common(Range r) {
    		if(disjoint(r))
    			return Range();
    		vector<int> integers;
    		integers.push_back(r.low);
    		integers.push_back(r.high);
    		integers.push_back(this->low);
    		integers.push_back(this->high);
    		sort(integers.begin(), integers.end());
    		return Range(integers[1], integers[2]);
    	}
    	
    	 enum Relation {
                SUBSET, SUPERSET, OVERLAPLEFT, OVERLAPRIGHT, TOUCHINGLEFT, TOUCHINGRIGHT, LEFTDISJOINT, RIGHTDISJOINT, SAME
            };
            Relation classify(Range r) {
                if (this->high == r.low) 
                    return TOUCHINGRIGHT;
                if (this->low == r.high)
                    return TOUCHINGLEFT;
                if (equals(r))
                    return SAME;
                if (contains(r)) 
                    return SUPERSET;
                if (r.contains(*this))
                    return SUBSET;
                if (disjoint(r))
                    if (this->low > r.high)
                        return RIGHTDISJOINT;
                    else
                        return LEFTDISJOINT;
                if (lessThan(r))
                    return OVERLAPLEFT;
                return OVERLAPRIGHT;
            }
};
