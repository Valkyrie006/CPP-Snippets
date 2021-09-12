const ll N = 5e5+5;
ll End[N];
ll nxt[N][26];

bool created[N];
ll siz = 0;

void insert(string &s)
{
	ll v = 0;
	for(ll i = 0; i < sz(s); i++)
	{
		ll c = s[i]-'a';
		if(!created[nxt[v][c]])
		{
			nxt[v][c] = ++siz;
			created[siz] = 1;
		}
		v = nxt[v][c];
	}
	++End[v];
}

ll search(string &tmp)
{
	ll v = 0;
	for(ll i = 0; i < sz(tmp); i++)
	{
		ll c = tmp[i] - 'a';
		if(!created[nxt[v][c]])
		{
			return 0;
		}
		v = nxt[v][c];
	}
	return (End[v] > 0);
}
