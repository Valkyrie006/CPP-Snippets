//Dfs to check cycle in a graph
ll f = 0;
void dfs(int v, int p)
{
	col[v] = 1;//Grey
	for(int u : G[v])
	{
		if(col[u] == 1)//Found cycle
			f++;
		else
			dfs(u, v);
	}
	col[v] = 2;//Black
}