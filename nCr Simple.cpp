ll ans = 0;
ll nCr2(ll n,ll r)
{
	ans = 1;
	ll k = 1;
	for(ll i = n; i>n-r; i--)
	{
		ans *= i;
		ans /= k;
		k++;
	}
	return ans;
}
