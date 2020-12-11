vll bin(32);
void decToBinary(ll n) 
{   
	rep(i, 32)
		bin[i] = 0;
    ll i = 0; 
    while (n > 0) { 
  
        bin[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 	
} //O(logn)
