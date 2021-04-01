class DSU {
    int n;
    vector<int> par, siz;

    public :
        DSU(int x) {
            n = x;
            par.resize(n + 1), siz.resize(n + 1);
            for (int i = 1; i <= n; i++)
                par[i] = i, siz[i] = 0;
        }
        
        // O(1)
        void make_set(int u) {
            par[u] = u;
            siz[u] = 1;
        }

        // O(logn)
        int find_set(int u) {
            if (u == par[u])
                return u;
            return par[u] = find_set(par[u]);
        }

        // O(1)
        void union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                if (siz[a] < siz[b])
                    swap(a, b);
                par[b] = a;
                siz[a] += siz[b];
            }
        }
};