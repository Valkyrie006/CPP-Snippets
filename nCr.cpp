ll modpow(ll a, ll b)
{
    ll ans =1;
    while(b>0){
        if(b&1){
            ans= ans * a % mod;
        }
        a = a * a % mod;
        b>>=1;
    }
    return(ans);
}

ll fac[100001];
void factorial(ll n)
{
	fac[0]=1;
	for(ll i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
	}
}

ll modInv(ll a)
{
	return modpow(a,mod-2)%mod;
}

ll nCr(ll n,ll r)
{
	ll b=modInv(fac[n-r]);
	ll c=modInv(fac[r]);
	ll a=fac[n]*b;
	a%=mod;
	a*=c;
	a%=mod;
	return a;
}