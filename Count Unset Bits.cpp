ll countUnsetBits(ll n) 
{ 
    int x = n; 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    return  __builtin_popcount(x ^ n); 
} //O(logn)
