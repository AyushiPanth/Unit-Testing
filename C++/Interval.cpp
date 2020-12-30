#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
	public:
	    int low;
	    int high;
	
	public:
	    Interval() {
	    	this->low = 0;
		    this->high = 0;
	    }

	    Interval(int end) {
		    this->low = 0;
		    this->high = end;
	    }

	    Interval(int first, int second) {
	    	this->low = min(first, second);
		    this->high = max(first, second);
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
    		return this->high - this->low;
    	}
    	
    	string toString() {
    		return "[" + to_string(this->low) + "," + to_string(this->high) + "]";
    	}
    
    	bool contains(int element) {
    		return this->low <= element && element <= this->high;
    	}
    
    	bool contains(Interval r) {
    		return this->low <= r.low && this->high >= r.high;
    	}
    
    	bool equals(Interval r) {
    		return r.low == this->low && r.high == this->high; 
    	}
    
    	bool disjoint(Interval r) {
    		return r.low > this->high || r.high < this->low; 
    	}
    
    	bool overlap(Interval r) {
    		return !(this->disjoint(r));
    	}
    
    	bool lessThan(Interval r) {
    		return this->low < r.low;
    	}
    
    	bool greaterThan(Interval r) {
    		return this->low > r.low;
    	}
    
    	bool touching(Interval r) {
    		return r.low == this->low || r.high == this->high;
    	}
    	
    	Interval merge(Interval r) {
    		if(disjoint(r))
    			return Interval();
    		return Interval(min(low, r.low), max(high, r.high));
    	}
    	
    	Interval common(Interval r) {
    		if(disjoint(r))
    			return Interval();
    		vector<int> integers;
    		integers.push_back(r.low);
    		integers.push_back(r.high);
    		integers.push_back(this->low);
    		integers.push_back(this->high);
    		sort(integers.begin(), integers.end());
    		return Interval(integers[1], integers[2]);
    	}
    	
    	 enum Relation {
                SUBSET, SUPERSET, OVERLAPLEFT, OVERLAPRIGHT, TOUCHINGLEFT, TOUCHINGRIGHT, LEFTDISJOINT, RIGHTDISJOINT, SAME
            };
            Relation classify(Interval r) {
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

class ClosedInterval : public Interval {
  public:
    ClosedInterval() {
      this->low = 0;
      this->high = 0;
    }
  
    ClosedInterval(int end) {
      this->low = 0;
      this->high = end;
    }
  
    ClosedInterval(int start, int end) {
      this->low = min(start, end);
      this->high = max(start, end);
    }
  
    string toString() {
    		return "[" + to_string(this->low) + "," + to_string(this->high) + "]";
    	}
  
    int length() {
    		return this->high - this->low + 1;
    	}
};

class OpenInterval : public Interval {
  public:
    OpenInterval() {
      this->low = 0;
      this->high = 0;
    }
  
    OpenInterval(int end) {
      this->low = 0;
      this->high = end;
    }
  
    OpenInterval(int start, int end) {
      this->low = min(start, end) - 1;
      this->high = max(start, end) - 1;
    }
  
    string toString() {
    		return "(" + to_string(this->low + 1) + "," + to_string(this->high + 1) + ")";
    	}
  
    int length() {
    		return this->high - this->low - 1;
    	}
};

class LeftHalfOpenInterval : public Interval {
  public:
    LeftHalfOpenInterval() {
      this->low = 0;
      this->high = 0;
    }
  
    LeftHalfOpenInterval(int end) {
      this->low = 0;
      this->high = end;
    }
  
    LeftHalfOpenInterval(int start, int end) {
      this->low = min(start, end) + 1;
      this->high = max(start, end);
    }
  
    string toString() {
    		return "(" + to_string(this->low + 1) + "," + to_string(this->high) + "]";
    	}
  
    int length() {
    		return this->high - this->low;
    	}
};

class RightHalfOpenInterval : public Interval {
  public:
    RightHalfOpenInterval() {
      this->low = 0;
      this->high = 0;
    }
  
    RightHalfOpenInterval(int end) {
      this->low = 0;
      this->high = end;
    }
  
    RightHalfOpenInterval(int start, int end) {
      this->low = min(start, end);
      this->high = max(start, end) - 1;
    }
  
    string toString() {
    		return "[" + to_string(this->low) + "," + to_string(this->high + 1) + ")";
    	}
  
    int length() {
    		return this->high - this->low;
    	}
};

int main() {
    Interval r1(10, 20);
    cout << r1.toString() << endl; 
    ClosedInterval r2(10, 20);
    cout << r2.toString() << endl;
    OpenInterval r3(10, 20);
    cout << r3.toString() << endl;
    RightHalfOpenInterval r4(10, 20);
    cout << r4.toString() << endl;
    LeftHalfOpenInterval r5(10, 20);
    cout << r5.toString() << endl;
}
