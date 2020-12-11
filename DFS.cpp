void dfs(ll v, ll p)
{
	vis[v]++;
	for(auto u : G[v])
	{
		if(!vis[u])
		{
			vis[u]++;
			//process
			dfs(u, p);
		}
	}
}

vll G[200005]; // graph represented as an adjacency list
int n; // number of vertices
vector<bool> vis;
void dfs2(int v)
{
    visited1[v] = true;
    for (int u : G[v]) {
        if (!visited1[u])
            dfs2(u);
    }
}
