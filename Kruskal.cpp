class Kruskal
{
    // Kruskal with DSU -> https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html
    // Time complexity - O(M*log(N))
    // M -> Number of edges, N -> Number of nodes

    vector<long long int> parent, Rank;

    void make_set(long long int v)
    {
        parent[v] = v;
        Rank[v] = 0;
    }

    long long int find_set(long long int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(long long int a, long long int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (Rank[a] < Rank[b])
                swap(a, b);
            parent[b] = a;
            if (Rank[a] == Rank[b])
                Rank[a]++;
        }
    }

    struct Edge
    {
        long long int u, v, weight;
        bool operator<(Edge const &other)
        {
            return weight < other.weight;
        }
    };

  public:
    // 0-based indexing
    long long int n; // Number of nodes
    vector<Edge> edges;
    long long int cost = 0;
    vector<Edge> result;

    Kruskal(long long int x)
    {
        n = x;
        parent.resize(n);
        Rank.resize(n);
        for (long long int i = 0; i < n; i++)
            make_set(i);
    }
    // Minimum Spanning Tree
    long long int MST()
    {
        sort(edges.begin(), edges.end());
        for (Edge e : edges)
        {
            if (find_set(e.u) != find_set(e.v))
            {
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);
                if ((long long int)result.size() == n - 1)
                {
                    break;
                }
            }
        }
        return cost;
    }
};

// Initialize by ->
// Kruskal K(n);
// K.edges.push_back({u, v, w});
// K.edges.push_back({v, u, w});