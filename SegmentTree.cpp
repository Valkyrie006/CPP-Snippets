#include<bits/stdc++.h>
using namespace std;

// To initialize ->
// segtree st;
// st.init(n);
// st.build(A);
struct segtree {
	long long int size;
	vector<long long int> T; // change this when min and count in range to vector<item> T;
	
	long long int combine(long long int a, long long int b) {
		return a + b; // For sum(or gcd, max, min, etc)
		// To calculate min and count of min in range long long int combine(long long int a, long long int b) -> item combine(item a, item b)
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
	
	void init(long long int n) {
		size = 1;
		while(size < n) {
			size *= 2;
		}
		T.resize(2*size);
	}
	
	void build(vector<long long int> &A, long long int x, long long int lx, long long int rx) {
		if(rx-lx == 1) {
			if(lx < (long long int)A.size()) {
				T[x] = A[lx]; // change this when min and count in range
			}
			return;
		}
		long long int m = (lx + rx) / 2;
		build(A, 2*x+1, lx, m);
		build(A, 2*x+2, m, rx);
		T[x] = combine(T[2*x+1], T[2*x+2]);
	}
	
	void build(vector<long long int> &A) {
		build(A, 0, 0, size);
	}
	
		
	void update(long long int i, long long int v, long long int x, long long int lx, long long int rx) {
		if(rx-lx == 1) {
			T[x] = v;  // change this when min and count in range to T[x] = {v, 1}
			return;
		}
		long long int m = (lx + rx) / 2;
		 if(i < m) {
		 	update(i, v, 2*x+1, lx, m);
		 }
		 else {
		 	update(i, v, 2*x+2, m, rx);
		 }
		 T[x] = combine(T[2*x+1], T[2*x+2]);
	}
	
	void update(long long int i, long long int v) {
		update(i, v, 0, 0, size);
	}
	
	
	// change this when min and count in range long long int query(long long int l, long long int r) -> item query(long long int l, long long int r, long long int x, long long int lx, long long int rx)
	long long int query(long long int l, long long int r, long long int x, long long int lx, long long int rx) {
		if(lx >= r || rx <= l) {
			return 0; // In case of sum or gcd or xor returned value is 0
			// return 1; // In case of multiply returned value is 1
			// return long long int_MAX; // In case of min returned value is long long int_MAX
			// return long long int_MIN; // In case of max returned value is long long int_MIN
			// change this when min and count in range to {long long int_MAX, 0}
		}
		if(lx >= l && rx <= r) {
			return T[x]; 
		}
		long long int m = (lx + rx) / 2;
		return combine(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
	}
	
    // Gives for [l, r-1]
	// change this when min and count in range long long int query(long long int l, long long int r) -> item query(long long int l, long long int r)
	long long int query(long long int l, long long int r) {
		return query(l, r, 0, 0, size);
	}
};

long long int main() {
	long long int n, q;
	cin>>n;
	vector<long long int> A(n);
	for(long long int i = 0; i < n; i++)
		cin>>A[i];
	
	segtree st;
	st.init(n);
	st.build(A);
	
	for(long long int i = 0; i < q; i++) {
		
	}
		
}