// index of root = 1
// T1 : array value type
// T2 : action type

template <class U>
struct segtree {
    using T1 = typename U::T1;
    using T2 = typename U::T2;
    int sz, H;

    V<T1> a;
    V<T2> b;

    segtree() { sz = H = -1; }
    segtree(int n) {
        sz = 1, H = 0;
        while (sz < n) {
            sz *= 2, ++H;
        }
        a.assign(sz * 2, U::id1());
        b.assign(sz * 2, U::id2());
    }

    segtree(const V<T1>& vec) {
        int n = vec.size();
        sz = 1, H = 0;
        while (sz < n) {
            sz *= 2, ++H;
        }

        a.assign(sz * 2, U::id1());
        b.assign(sz * 2, U::id2());

        for (int i = 0; i < n; ++i) {
            a[sz + i] = vec[i];
        }
        for (int i = sz - 1; i >= 1; --i) {
            a[i] = U::op11(a[(i << 1) | 0], a[(i << 1) | 1]);
        }
    }

    inline T1 reflect(int k) {
        return b[k] == U::id2() ? a[k] : U::op21(b[k], a[k]);
    }

    void up(int i) {
        while (i >>= 1) {
            a[i] = U::op11(reflect((i << 1) | 0), reflect((i << 1) | 1));
        }
    }

    void propagate(int p) {
        for (int h = H; h > 0; --h) {
            int i = p >> h;
            a[i] = reflect(i);
            b[i << 1 | 0] = U::op22(b[i], b[i << 1 | 0]);
            b[i << 1 | 1] = U::op22(b[i], b[i << 1 | 1]);
            b[i] = U::id2();
        }
    }

    void set(int p, T1 x) {
        p += sz;
        propagate(p);
        a[p] = x;
        b[p] = U::id2();
        up(p);
    }

    T1 get(int p) {
        p += sz;
        propagate(p);
        return reflect(p);
    }

    // action on [p, q)
    void apply(int p, int q, T2 x) {
        if (p >= q) return;
        p += sz, q += sz;
        propagate(p);
        propagate(q - 1);

        for (int l = p, r = q; l < r; l >>= 1, r >>= 1) {
            if (l & 1) b[l] = U::op22(x, b[l]), l++;
            if (r & 1) --r, b[r] = U::op22(x, b[r]);
        }
        up(p);
        up(q - 1);
    }

    T1 get(int l, int r) {
        if (l >= r) return U::id1();
        l += sz, r += sz;
        propagate(l);
        propagate(r - 1);

        T1 lval = U::id1(), rval = U::id1();

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op11(lval, reflect(l++));
            if (r & 1) rval = U::op11(reflect(--r), rval);
        }
        return U::op11(lval, rval);
    }
};

/*
ABC 237 G
https://atcoder.jp/contests/abc237/submissions/30181965
struct U {
    // number of 1, all
    using T1 = pii;
    using T2 = int;
    static T1 id1() { return mp(0, 0); }
    static T2 id2() { return -1; }
    static T1 op11(const T1& a, const T1& b) {
        return mp(a.fi + b.fi, a.se + b.se);
    }

    static T1 op21(const T2& b, const T1& a) {
        pii res = a;
        if (b == 0)
            res.fi = 0;
        else if (b == 1)
            res.fi = res.se;
        return res;
    }
    // a : new!
    static T2 op22(const T2& a, const T2& b) {
        if (a == id2())
            return b;
        else
            return a;
    }
};/*