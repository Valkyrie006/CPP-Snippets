ll binarySearch(vector<ll> v, ll l, ll r, ll x)//l->left index, r->right index, x->No to check
{
	vector<ll> A;
	A=v;
	sort(A.begin(), A.end());
	while(l <= r)
	{
		ll ans;
        ll mid = l+(r-l)/2;
        if(A[mid] == x)
            return mid;
            
		else if(A[mid]<x)
			l = mid+1;
			
		else
			r=mid-1;
    }
}
