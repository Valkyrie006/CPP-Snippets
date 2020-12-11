const ll MAXN = 1e5+5;
ll n;
pll T[4*MAXN], A[MAXN];
//A[i] = {val, pos} -> RMQ(Max, pos)
//A[i] = {val, 1} -> RMQ(Max, cnt)

pll combine(pll a, pll b)
{
	//RSQ
	//return (a+b); //{a, b, A, T are ll not pll}
	
	//RMQ(Max, id)
	if(a.F > b.F)
		return a;
	if(b.F > a.F)
		return b;
	
	return a;//Find first occurance {a.F, min(a.S, b.S)} and last occurance {a.F, max(a.S, b.S)}
	//return {a.F, a.S+b.S}; //RMQ(Max, cnt)
}
//initialize with build() for 1 based indexing {1, 1, n}
void build(ll id = 1, ll tl = 1, ll tr = n)
{
	if(tl == tr)
		T[id] = A[tl];
	else
	{
		ll tm = (tl+tr)/2;
		build(2*id, tl, tm);
		build(2*id+1, tm+1, tr);
		T[id] = combine(T[2*id], T[2*id+1]);
	}
}

//sum of elements from l to r
//Max Element with index
//Max element with count
pll query(ll l, ll r, ll id = 1, ll tl = 1, ll tr = n)
{
	if(l > r)
		return {-1, 1};//For mini-> {INT_MAX, 1};
	if(l == tl && r == tr)
		return T[id];
	ll tm = (tl+tr)/2;
	return combine(query(l, min(tm, r), 2*id, tl, tm), query(max(l, tm+1), r, 2*id+1, tm+1, tr));
}

// update val of element at pos 
void update(ll pos, ll val, ll id = 1, ll tl = 1, ll tr = n)
{
	if(tl == tr)
	{
		T[id] = {val, pos};// For {max, pos}
		//T[id] = {val, 1}; //For {max, cnt}
		//A[pos] = val;
	}
	else
	{
		ll tm = (tl+tr)/2;
		if(pos <= tm)
			update(pos, val, 2*id, tl, tm);
		else
			update(pos, val, 2*id+1, tm+1, tr);
		T[id] = combine(T[2*id], T[2*id+1]);
	}
}
