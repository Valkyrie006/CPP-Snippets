// change item
struct item
{
    int m, c;
    // int sum;  //=> For sum
};

struct segtree
{
    int size;
    vector<item> values;

    // change NEUTRAL_ELEMENT, merge, single

    item NEUTRAL_ELEMENT = {INT_MAX, 0};
    // item NEUTRAL_ELEMENT = {0} // => for sum
    item merge(item a, item b)
    {
        if (a.m < b.m)
            return a;
        if (a.m > b.m)
            return b;
        return {a.m, a.c + b.c};
        // return {a.sum + b.sum} // => for sum
    }

    item single(int v)
    {
        return {v, 1};
        // return {v} // => for sum
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.resize(2 * size);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    item calc(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return values[x];
        int m = (lx + rx) / 2;
        item s1 = calc(l, r, 2 * x + 1, lx, m);
        item s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    item calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
};
