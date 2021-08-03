#include<bits/stdc++.h>
using namespace std;

// To initialize ->
// segtree st;
// st.init(n);
// st.build(A);
struct segtree {
	int size;
	vector<int> T; // change this when min and count in range to vector<item> T;
	
	int combine(int a, int b) {
		return a + b; // For sum(or gcd, max, min, etc)
		// To calculate min and count of min in range int combine(int a, int b) -> item combine(item a, item b)
		// if(a.m < b.m) {
			// return a;
		// }
		// else if(a.m > b.m) {
			// return b;
		// }
		// else {
			// return {a.m, a.c + b.c};
		// }
	}
	
	void init(int n) {
		size = 1;
		while(size < n) {
			size *= 2;
		}
		T.resize(2*size);
	}
	
	void build(vector<int> &A, int x, int lx, int rx) {
		if(rx-lx == 1) {
			if(lx < (int)A.size()) {
				T[x] = A[lx]; // change this when min and count in range
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(A, 2*x+1, lx, m);
		build(A, 2*x+2, m, rx);
		T[x] = combine(T[2*x+1], T[2*x+2]);
	}
	
	void build(vector<int> &A) {
		build(A, 0, 0, size);
	}
	
		
	void update(int i, int v, int x, int lx, int rx) {
		if(rx-lx == 1) {
			T[x] = v;  // change this when min and count in range to T[x] = {v, 1}
			return;
		}
		int m = (lx + rx) / 2;
		 if(i < m) {
		 	update(i, v, 2*x+1, lx, m);
		 }
		 else {
		 	update(i, v, 2*x+2, m, rx);
		 }
		 T[x] = combine(T[2*x+1], T[2*x+2]);
	}
	
	void update(int i, int v) {
		update(i, v, 0, 0, size);
	}
	
	
	// change this when min and count in range int query(int l, int r) -> item query(int l, int r, int x, int lx, int rx)
	int query(int l, int r, int x, int lx, int rx) {
		if(lx >= r || rx <= l) {
			return 0; // In case of sum or gcd or xor returned value is 0
			// return 1; // In case of multiply returned value is 1
			// return INT_MAX; // In case of min returned value is INT_MAX
			// return INT_MIN; // In case of max returned value is INT_MIN
			// change this when min and count in range to {INT_MAX, 0}
		}
		if(lx >= l && rx <= r) {
			return T[x]; 
		}
		int m = (lx + rx) / 2;
		return combine(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
	}
	
	// change this when min and count in range int query(int l, int r) -> item query(int l, int r)
	int query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

int main() {
	int n, q;
	cin>>n;
	vector<int> A(n);
	for(int i = 0; i < n; i++)
		cin>>A[i];
	
	segtree st;
	st.init(n);
	st.build(A);
	
	for(int i = 0; i < q; i++) {
		
	}
		
}