const int N = 1e5 + 5;
int n, m;
vector<vector<int>> G(N);
vector<int> inDegree(N), order;

bool topological_sort()
{
    order.clear();
    for (int u = 0; u < n; u++)
    {
        for (auto v : G[u])
            inDegree[v]++;
    }
    queue<int> q;
    for (int u = 0; u < n; u++)
    {
        if (inDegree[u] == 0)
            q.push(u);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto v : G[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }
    if(order.size() != n)
    	return 1;
    else 
    	return 0;
}