ll modadd(ll a, ll b)
{
   ll c =  ((a%mod)+(b%mod)+mod)%mod;
   c = (c+mod)%mod;
   return c;
}

ll modsub(ll a, ll b)
{
	return (((a - b) % mod) + mod) % mod;
}

ll modmul(ll a, ll b)
{
   return ((a%mod)*1ll*(b%mod))%mod;
}

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

ll modInv(ll a)
{
	return modpow(a,mod-2)%mod;
}

ll moddiv(ll a, ll b)
{
	return modmul(a, modInv(b));
}