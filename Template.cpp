#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define endl '\n'
#define maxl __LONG_LONG_MAX__
#define pb push_back
#define F first
#define S second
#define rep(i, n) for(int i = 0; i < n; i++)
#define rev(i, n) for(int i = n-1; i >= 0; i--)
#define rep1(i, n) for(int i=1; i < n; i++)
#define rev1(i, n) for(int i=n ; i > 0; i--)
#define n_ones(x) __builtin_popcountll(x)
#define n_trailzero(x) __builtin_ctzll(x)
#define n_leadingzero(x) __builtin_clz(x)
#define sz(a) (ll)(a.size())
#define all(v) v.begin(),v.end()
#define FASTIO {ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);}
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a/gcd(a, b))*b
#define PI 3.14159265358979323846
#define see(args...)                       \
{                                            \
    cerr<<"LINE "<<__LINE__;                 \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
    cerr<<endl;                              \
}
void err(istream_iterator<string> it){}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr<<' '<< *it << " = " << a ;
  err(++it, args...);
} 
template <typename T, typename U>inline void min_self(T &x, U y){if (y < x)x = y;}
template <typename T, typename U>inline void max_self(T &x, U y){if (x < y)x = y;}
template<class T1, class T2>ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<"["<<v.first<<", "<<v.second<<"]"; return out<<")"; }
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}


typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll> > vpll;
typedef vector<vector<ll> > vvll;

// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_setll;
// typedef tree<char,null_type,less<char>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_setc;

ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);}
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}

// cout<<fixed<<setprecision(20)<<pi<<endl; 

ll mod = 1e9 + 7;
ll Test, cas;

void solve() {
    
	return;
}

int main() {
	FASTIO;
	//Test = 1;
	cin>>Test;
	for(cas = 1; cas <= Test; cas++)
		solve();
	return 0;
}