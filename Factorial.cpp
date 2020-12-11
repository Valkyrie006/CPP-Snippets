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
