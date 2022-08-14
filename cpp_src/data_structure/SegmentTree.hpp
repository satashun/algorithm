// index of root = 1
template <class U>
struct segtree {
    using T = typename U::T;
    int sz;
    V<T> dat;

    segtree() {}
    segtree(int n) : _n(n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(sz * 2, U::id());
    }

    segtree(const V<T>& a) {
        int n = a.size();
        _n = n;
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(sz * 2, U::id());
        for (int i = 0; i < n; ++i) {
            dat[sz + i] = a[i];
        }
        for (int i = sz - 1; i >= 1; --i) {
            upd(i);
        }
    }

    void upd(int p) { dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]); }

    void build() {
        for (int i = sz - 1; i > 0; --i) {
            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);
        }
    }

    void modify(int p, T v) {
        p += sz;
        dat[p] = v;
        while (p >>= 1) {
            dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]);
        }
    }

    T get(int p) const { return dat[p + sz]; }

    //[l, r)
    T query(int l, int r) const {
        T lval = U::id(), rval = U::id();
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op(lval, dat[l++]);
            if (r & 1) rval = U::op(dat[--r], rval);
        }
        return U::op(lval, rval);
    }

    // https://atcoder.jp/contests/practice2/submissions/33977727
    // https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
    // find max r s.t. f([l, r)) = true
    template <class F>
    int max_right(int l, F f) const {
        // assert(0 <= l && l <= _n);
        // assert(f(U::id()));

        if (l == sz) return sz;
        l += sz;
        auto cur = U::id();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(U::op(cur, dat[l]))) {
                while (l < sz) {
                    l = l * 2;
                    if (f(U::op(cur, dat[l]))) {
                        cur = U::op(cur, dat[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            cur = U::op(cur, dat[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    // needs verification
    // find min l s.t. f([l, r)) = true
    template <class F>
    int min_left(int r, F f) const {
        // assert(0 <= r && r <= _n);
        // assert(f(U::id()));

        if (r == 0) return 0;
        r += sz;
        auto cur = U::id();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(U::op(dat[r], cur))) {
                while (r < sz) {
                    r = (2 * r + 1);
                    if (f(U::op(dat[r], cur))) {
                        cur = U::op(dat[r], cur);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            cur = U::op(dat[r], cur);
        } while ((r & -r) != r);
        return 0;
    }

   private:
    int _n;
};

constexpr int INF = TEN(9);

// modify only U
struct U {
    using T = int;
    static T id() { return INF; }
    static T op(const T& a, const T& b) { return min(a, b); }
};