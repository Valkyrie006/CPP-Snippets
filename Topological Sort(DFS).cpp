const int N = 2e5+5;
ll n, m;
vvll G(N);
vll vis, order;

void dfs1(int u)
{
	vis[u] = 1;
	for(int v : G[u])
	{
		if(!vis[v])
			dfs1(v);
	}	
	order.pb(u);
}

void topological_sort()
{
	vis.assign(n, 0);
	order.clear();
	
	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	reverse(all(order));
	
	return;
}
