class FenwickTree 
{
    vll fen;
	public:    
    	FenwickTree(int n) 
    	{
        	fen.assign(n + 1, 0);
    	}
 		
 		void SEE()
 		{
 			see(fen);
 		}
 		
    	ll sum(int b) // sum of freq. of pos 1 to pos b 
    	{ 
	        ll s = 0;
	        while (b > 0) 
	        {
	            s += fen[b];
	            b -= (b & (-b));
	        }
	        return s;
	    }
	    
	    ll sum(int a, int b) // sum of freq. of pos a to pos b 
	    {  
	        return sum(b) - sum(a-1);
	    }
	    
	    void add(int k, ll v) // add freq. v to pos k
	    { 
	        while (k < sz(fen)) 
	        {
	            fen[k] += v;
	            k += (k & (-k));
	        }
	    }
	 
	    int find(ll k) // kth order statistics using binary lifting(logn)
	    {   
	        ll s = 0;
	        int pos = 0;
	        int i = int(log2(sz(fen) - 1));
	        while (i >= 0) 
	        {
	            if (pos + (1 << i) < sz(fen) && s + fen[pos + (1 << i)] < k) 
	            {
	                s += fen[pos + (1 << i)];
	                pos += (1 << i);
	            }
	            i--;
	        }
	        return pos + 1;
	    }
	    int find2(ll k) // kth order statistics using binary search(logn*logn)
	    {
	    	ll l = 1, r = sz(fen)-1;
			ll pos = 0;
			while(l <= r)
			{
				ll mid = (l+r)/2;
				if(sum(mid) >= k)
				{
					pos = mid;
					r = mid - 1;
				}
				else
					l = mid + 1;
			}
			return pos;
	    }
};