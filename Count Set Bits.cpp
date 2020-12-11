ll countSetBits(ll n) 
{ 
    ll count = 0; 
    while (n)
	{ 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} //O(logn)
