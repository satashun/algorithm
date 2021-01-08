template <class T>
class segtree {
   public:
    VV<T> dat;
    int sz;

    segtree() = default;

    void init(const vector<T>& vec) {
        for (sz = 1; sz < (int)vec.size(); sz *= 2)
            ;
        dat.resize(sz * 2);

        rep(i, sz * 2) { dat[i].clear(); }

        rep(i, vec.size()) { dat[sz - 1 + i].pb(vec[i]); }

        for (int i = sz - 2; i >= 0; --i) {
            int lc = i * 2 + 1, rc = i * 2 + 2;
            dat[i].resize(dat[lc].size() + dat[rc].size());
            merge(dat[lc].begin(), dat[lc].end(), dat[rc].begin(),
                  dat[rc].end(), dat[i].begin());
        }
    }

    int ask(int a, int b, T t, int k, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) {
            return lower_bound(ALL(dat[k]), t) - dat[k].begin();
        }

        return ask(a, b, t, k * 2 + 1, l, (l + r) / 2) +
               ask(a, b, t, k * 2 + 2, (l + r) / 2, r);
    }

    int ask(int a, int b, T t) { return ask(a, b, t, 0, 0, sz); }
};