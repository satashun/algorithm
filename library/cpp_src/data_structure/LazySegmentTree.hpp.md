---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: cpp_src/data_structure/LazySegmentTree.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0efeb1959dbc8f7e9170e2d5bfa803ae">cpp_src/data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/data_structure/LazySegmentTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-17 17:57:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
            a[i] = U::op11(a[i << 1 | 0], a[i << 1 | 1]);
        }
    }

    void up(int i) {
        while (i >>= 1) {
            T1 xl = U::op21(b[i << 1 | 0], a[i << 1 | 0]);
            T1 xr = U::op21(b[i << 1 | 1], a[i << 1 | 1]);
            a[i] = U::op11(xl, xr);
        }
    }

    void propagate(int p) {
        for (int h = H; h > 0; --h) {
            int i = p >> h;
            a[i] = U::op21(b[i], a[i]);
            b[i << 1 | 0] = U::op22(b[i], b[i << 1 | 0]);
            b[i << 1 | 1] = U::op22(b[i], b[i << 1 | 1]);
            b[i] = U::id2();
        }
    }

    // action on [p, q)
    void apply(int p, int q, T2 x) {
        if (p == q) return;
        p += sz, q += sz;
        propagate(p);
        propagate(q - 1);

        for (int l = p, r = q; l < r; l >>= 1, r >>= 1) {
            if (l & 1) b[l] = U::op22(x, b[l]), ++l;
            if (r & 1) --r, b[r] = U::op22(x, b[r]);
        }
        up(p);
        up(q - 1);
    }

    T1 get(int l, int r) {
        if (l == r) return U::id1();
        l += sz, r += sz;
        propagate(l);
        propagate(r - 1);

        T1 lval = U::id1(), rval = U::id1();

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op11(lval, U::op21(b[l], a[l])), ++l;
            if (r & 1) --r, rval = U::op11(U::op21(b[r], a[r]), rval);
        }
        return U::op11(lval, rval);
    }
};

// for https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d
// range addition and range minimum query needed, initialization must be cared
// (set all to 0, while id1 = INF)

// modify only U for use

constexpr ll INF = TEN(18);

struct U {
    using T1 = ll;
    using T2 = ll;
    static T1 id1() { return INF; }
    static T2 id2() { return 0; }
    static T1 op11(const T1& a, const T1& b) { return min(a, b); }
    static T1 op21(const T2& b, const T1& a) { return b + a; }
    static T2 op22(const T2& a, const T2& b) { return a + b; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/data_structure/LazySegmentTree.hpp"
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
            a[i] = U::op11(a[i << 1 | 0], a[i << 1 | 1]);
        }
    }

    void up(int i) {
        while (i >>= 1) {
            T1 xl = U::op21(b[i << 1 | 0], a[i << 1 | 0]);
            T1 xr = U::op21(b[i << 1 | 1], a[i << 1 | 1]);
            a[i] = U::op11(xl, xr);
        }
    }

    void propagate(int p) {
        for (int h = H; h > 0; --h) {
            int i = p >> h;
            a[i] = U::op21(b[i], a[i]);
            b[i << 1 | 0] = U::op22(b[i], b[i << 1 | 0]);
            b[i << 1 | 1] = U::op22(b[i], b[i << 1 | 1]);
            b[i] = U::id2();
        }
    }

    // action on [p, q)
    void apply(int p, int q, T2 x) {
        if (p == q) return;
        p += sz, q += sz;
        propagate(p);
        propagate(q - 1);

        for (int l = p, r = q; l < r; l >>= 1, r >>= 1) {
            if (l & 1) b[l] = U::op22(x, b[l]), ++l;
            if (r & 1) --r, b[r] = U::op22(x, b[r]);
        }
        up(p);
        up(q - 1);
    }

    T1 get(int l, int r) {
        if (l == r) return U::id1();
        l += sz, r += sz;
        propagate(l);
        propagate(r - 1);

        T1 lval = U::id1(), rval = U::id1();

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op11(lval, U::op21(b[l], a[l])), ++l;
            if (r & 1) --r, rval = U::op11(U::op21(b[r], a[r]), rval);
        }
        return U::op11(lval, rval);
    }
};

// for https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d
// range addition and range minimum query needed, initialization must be cared
// (set all to 0, while id1 = INF)

// modify only U for use

constexpr ll INF = TEN(18);

struct U {
    using T1 = ll;
    using T2 = ll;
    static T1 id1() { return INF; }
    static T2 id2() { return 0; }
    static T1 op11(const T1& a, const T1& b) { return min(a, b); }
    static T1 op21(const T2& b, const T1& a) { return b + a; }
    static T2 op22(const T2& a, const T2& b) { return a + b; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

