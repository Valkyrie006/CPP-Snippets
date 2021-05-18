const int N = 1e5 + 5;
vector<int> G[N];
int subTree[N];
int nodes;

void dfs(int u, int par) {
    nodes++;
    subTree[u] = 1;
    for(auto v: G[u]) {
        if(v == par)
            continue;
        dfs(v, u);
        subTree[u] += subTree[v];
    }
}

int centroid(int u, int par) {
    for(auto v: G[u]) {
        if(v == par)
            continue;
        if(subTree[v] > (nodes>>1))
            return centroid(v, u);
    }
    return u;
}

// Initialize
// nodes = 0;
// dfs(u, u);
// int node = centroid(u, u);

// For centroid Decomposition define set<int> G[N] and do something like this
// void decompose(ll u, char ch)
// {
//     nodes = 0;
//     dfs(u, u);
//     ll node = centroid(u, u);
//     ans[node] = ch;
//     for (auto v : G[node])
//     {
//         G[v].erase(node);
//         decompose(v, ch + 1);
//     }
// }

// Time Complexity - Finding centroid - O(N)
// Time Complexity - Centroid Decomposition - O(Nlog(N))