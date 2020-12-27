#include <iostream>
using namespace std;

class Range {
	protected int low;
	protected int high;
	
	public void Range() {
		this.low = 0;
		this.high = 0;
	}

	public void Range(int end) {
		this.low = 0;
		this.end = end;
	}

	public void Range(int first, int second) {
		this.low = min(first, second);
		this.high = max(first, second) - 1;
	}

	public reset() {
		this.low = 0;
		this.high = 0;
	}

	public void rightStretch() {
		this.high++;
	}

	public void rightStretch(int size) {
		this.high += size;
	}

	public void leftStretch() {
		this.low--;
	}

	public void leftStretch(int size) {
		this.low -= size;
	}

	public void stretch() {
		this.low--;
		this.high++;
	}

	public void stretch(int size) {
		this.low -= size;
		this.high += size;
	}

	public void squeeze() {
		this.low++;
		this.high--;
		if(this.low > this.high)
			this.reset();
	}

	public void squeeze(int size) {
		this.low += size;
		this.high -= size;
		if(this.low > this.high)
			this.reset();
	}
	
	public void shift(int shifter) {
		this.low += shifter;
		this.high += shifter;
	}

	public int length() {
		return this.high - this.low + 1;
	}
	
	public string toString() {
		return "[" + toString(this.low) + "," + toString(this.high + 1) + ")";
	}

	public bool contains(int element) {
		return this.low <= element && element <= this.high;
	}

	public bool contains(Range r) {
		return this.low <= r.low && this.high >= r.high;
	}

	public bool equals(Range r) {
		return r.low == this.low && r.high == this.high; 
	}

	public bool disjoint(Range r) {
		return r.low > this.high || r.high < this.low; 
	}

	public bool overlap(Range r) {
		return !(this.disjoint(r));
	}

	public bool lessThan(Range r) {
		return this.low < r.low;
	}

	public bool greaterThan(Range r) {
		return this.low > r.low;
	}

	public bool touching(Range r) {
		return r.low == this.low || r.high == this.high;
	}

}
