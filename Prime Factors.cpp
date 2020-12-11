vll prime;
void primeFactors(ll n)
{
	ll res=0;
	while(n%2==0){
		prime.pb((ll)2);
		n>>=1;
	}
	for (ll i=3 ; i*i<=n ; i+=2)
	{
		while(n%i == 0)
		{
			prime.pb(i);
			n/=i;
		}
	}
	if(n>2)
	{
		prime.pb(n);
	}
	return;
}
