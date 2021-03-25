int n, m;
const int N = 2e5 + 5;
vector<vector<int>> G(N);
vector<int> color(N);

bool bipartite(int u)
{
    for (int i = 1; i <= n; i++)
    {
        color[i] = -1;
    }
    queue<int> q;
    q.push(u);
    color[u] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int v : G[x])
        {
            if (color[v] == -1)
            {
                color[v] = 3 - color[x];
                q.push(v);
            }
            else if (color[v] + color[x] != 3)
                return 0;
        }
    }
    return 1;
}