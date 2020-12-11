void bfs(ll v)
{
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	vis[v]++;
	while(!q.empty())
	{
		ll a=q.front();
		q.pop();
		for(auto u : G[v])
		{
			if(!vis[u])
			{
				vis[u]++;
				dist[u] = dist[a]+1;
				q.push(u);
			}
		}
	}
}

void bfs2(vector<ll> v[],ll o,ll n)
{
	queue<ll> q;
	q.push(o);
	bool vis[n+1]={false};
	visited[o]=true;
	while(!q.empty())
	{
		ll a=q.front();
		q.pop();
		ll count=0;
		for(ll i=0; i<v[a].size(); i++)
		{
			if(vis[v[a][i]]==false)
			{
				vis[v[a][i]]=true;
				q.push(v[a][i]);
				count++;
			}
		}
	}
}
