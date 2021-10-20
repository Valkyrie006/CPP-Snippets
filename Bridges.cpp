// https://codeforces.com/blog/entry/71146
class Bridges
{
    long long int n, Time;
    vector<vector<long long int>> G;
    vector<vector<long long int>> BR;  // bridges
    vector<long long int> low; // for every node U we have to find the node V with the least discovery time that can be
                               // reached from U following some DFS traversal path which does not require to pass
                               // through any already visited nodes, and let's call this node low
    vector<long long int> entryTime; // discovery/entry time of node
  public:
    Bridges(vector<vector<long long int>> &adj, long long int N)
    {
        G = adj;
        n = N;
        low = entryTime = vector<long long int>(n);
        Time = 0;
        for (long long int u = 0; u < G.size(); u++)
        {
            if (entryTime[u] == 0)
            {
                dfsBR(u, u);
            }
        }
    }
    void dfsBR(long long int u, long long int p)
    {
        low[u] = entryTime[u] = ++Time;
        for (long long int &v : G[u])
        {
            if (v == p)
            {
                continue;
            }
            if (!entryTime[v])
            {
                dfsBR(v, u);
                if (entryTime[u] < low[v]) // condition to find bridge
                    BR.push_back({u, v});
                low[u] = min(low[u], low[v]);// low[v] might be an ancestor of u
            }
            else                                    // if v was already discovered means that we found an ancestor
                low[u] = min(low[u], entryTime[v]); // finds the ancestor with the least discovery time
        }
    }
};