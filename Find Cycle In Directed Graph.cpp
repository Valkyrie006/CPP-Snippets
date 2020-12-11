const int N = 2e5+5;
ll n, m;
vvll G(N);
vll color, parent;
int cycle_start, cycle_end;

bool dfs2(int u)
{
	color[u] = 1;
	for(auto v : G[u])
	{
		if(color[v] == 0)
		{
			parent[v] = u;
			if(dfs2(v))
				return 1;
		}
		else if(color[v] == 1)
		{
			cycle_end = u;
			cycle_start = v;
			return 1;
		}
	}	
	color[u] = 2;
	return 0;
}

bool find_cycle()
{
	color.assign(n, 0);
	parent.assign(n, -1);
	cycle_start = -1;
	
	for(int i = 0; i < n; i++)
	{
		if(color[i] == 0 && dfs2(i))
			break;
	}	
	if(cycle_start == -1)
		return 0;
	else
	{
		vll cycle;
		cycle.pb(cycle_start);
		for(int v = cycle_end; v != cycle_start; v = parent[v])
		{
			cycle.pb(v);
		}
		cycle.pb(cycle_start);
		reverse(all(cycle));
		//here you can print the cycle or delete this code
		return 1;
	}
}
