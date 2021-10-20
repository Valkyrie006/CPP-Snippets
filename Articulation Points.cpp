// Articulation Point - We say that a vertex V in a graph G with C connected components is an articulation point if its removal increases the number of connected components of G
// https://codeforces.com/blog/entry/71146
class articulationPoints
{
    long long int n, Time;
    vector<vector<long long int>> G;
    vector<long long int> AP;  // articulation points
    vector<long long int> low; // for every node U we have to find the node V with the least discovery time that can be
                               // reached from U following some DFS traversal path which does not require to pass
                               // through any already visited nodes, and let's call this node low
    vector<long long int> entryTime; // discovery/entry time of node
  public:
    articulationPoints(vector<vector<long long int>> &adj, long long int N)
    {
        G = adj;
        n = N;
        AP = low = entryTime = vector<long long int>(n);
        Time = 0;
        for (long long int u = 0; u < G.size(); u++)
        {
            if (entryTime[u] == 0)
            {
                AP[u] = dfsAP(u, u) > 1; // condition #2
            }
        }
    }
    long long int countOfAP()
    {
        return n - count(AP.begin(), AP.end(), 0LL);
    }
    long long int dfsAP(long long int u, long long int p)
    {
        long long int children = 0;
        low[u] = entryTime[u] = ++Time;
        for (long long int &v : G[u])
        {
            if (v == p)
            {
                continue;
            }
            if (!entryTime[v])
            {
                children++;
                dfsAP(v, u);
                if (entryTime[u] <= low[v]) // condition #1
                    AP[u] = 1;
                low[u] = min(low[u], low[v]);
            }
            else                                    // if v was already discovered means that we found an ancestor
                low[u] = min(low[u], entryTime[v]); // finds the ancestor with the least discovery time
        }
        return children;
    }
};