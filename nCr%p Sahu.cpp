class class_ncr{
    public:
        //Variables
        ll N;
        vi fact;
       
        // Constructor
        class_ncr(ll x){
            N = x;
            fact.resize(N+1);
            fact[0] = 1;
            rep(i,1,N) fact[i] = fact[i-1]*i%mod;
        }
       
        // Methods
        ll ncr(ll n,ll r){
            return fact[n] * inverse(fact[r]) % mod * inverse(fact[n - r]) % mod;
        }
    private:
        ll euclid(ll a, ll b, ll& x, ll& y) {
            if (b == 0) {
                x = 1;
                y = 0;
                return a;
            }
            ll x1, y1;
            ll d = euclid(b, a % b, x1, y1);
            x = y1;
            y = x1 - y1 * (a / b);
            return d;
        }
        ll inverse(ll a){
            ll x,y;
            euclid(a,mod,x,y);
            if(x<0) x = mod + x;
            return x;
           
        }
};
 
// Initialise a global object of the class before use... like --
// class_ncr {object name}(maximum n for which ncr is required)
 
 
class_ncr combi(2000);
 