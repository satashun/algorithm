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


# :heavy_check_mark: test/yosupo/point_set_range_composite.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_set_range_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 02:45:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/cpp_src/math/modint.hpp.html">cpp_src/math/modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#define call_from_test
#include "../../cpp_src/math/modint.hpp"
#undef call_from_test

using Mint = ModInt<998244353>;

//index of root = 1

template<class U>
struct segtree {
	using T = typename U::T;
	int sz;
	V<T> dat;

	segtree(const V<T>& a) {
		int n = a.size();
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

	void upd(int p) {
		dat[p] = U::op(dat[p<<1], dat[p<<1|1]);
	}

	void build() {
		for (int i = sz - 1; i > 0; --i) {
			dat[i] = U::op(dat[i<<1], dat[i<<1|1]);		
		}
	}

	void modify(int p, T v) {
		p += sz;
		dat[p] = v;
		while (p >>= 1) {
			dat[p] = U::op(dat[p<<1], dat[p<<1|1]);
		}
	}

	//[l, r)

	T query(int l, int r) {
		T lval = U::id(), rval = U::id();
		int res = 0;
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lval = U::op(lval, dat[l++]);
			if (r & 1) rval = U::op(dat[--r], rval);
		}
		return U::op(lval, rval);
	}
};

const int INF = TEN(9) + 10;

struct U {
    using T = pair<Mint, Mint>;
    static T id() { return mp(Mint(1), Mint(0)); }
    static T op(const T& a, const T& b) {
    	return mp(a.first * b.first, a.second * b.first + b.second);
    }
};

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	V<pair<Mint, Mint>> vec(N);

	rep(i, N) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[i] = mp(Mint(a), Mint(b));
	}
	segtree<U> seg(vec);
	while (Q--) {
		int t; scanf("%d", &t);
		if (t == 0) {
			int p, c, d;
			scanf("%d %d %d", &p, &c, &d);
			seg.modify(p, mp(Mint(c), Mint(d)));
		} else {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			auto f = seg.query(l, r);
			printf("%d\n", (f.fi * Mint(x) + f.se).v);
		}
	}

	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_set_range_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#define call_from_test
#line 1 "cpp_src/math/modint.hpp"
template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    static uint get_mod() { return MOD; }
};

// using Mint = ModInt<1000000007>;
#line 50 "test/yosupo/point_set_range_composite.test.cpp"
#undef call_from_test

using Mint = ModInt<998244353>;

//index of root = 1

template<class U>
struct segtree {
	using T = typename U::T;
	int sz;
	V<T> dat;

	segtree(const V<T>& a) {
		int n = a.size();
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

	void upd(int p) {
		dat[p] = U::op(dat[p<<1], dat[p<<1|1]);
	}

	void build() {
		for (int i = sz - 1; i > 0; --i) {
			dat[i] = U::op(dat[i<<1], dat[i<<1|1]);		
		}
	}

	void modify(int p, T v) {
		p += sz;
		dat[p] = v;
		while (p >>= 1) {
			dat[p] = U::op(dat[p<<1], dat[p<<1|1]);
		}
	}

	//[l, r)

	T query(int l, int r) {
		T lval = U::id(), rval = U::id();
		int res = 0;
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lval = U::op(lval, dat[l++]);
			if (r & 1) rval = U::op(dat[--r], rval);
		}
		return U::op(lval, rval);
	}
};

const int INF = TEN(9) + 10;

struct U {
    using T = pair<Mint, Mint>;
    static T id() { return mp(Mint(1), Mint(0)); }
    static T op(const T& a, const T& b) {
    	return mp(a.first * b.first, a.second * b.first + b.second);
    }
};

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	V<pair<Mint, Mint>> vec(N);

	rep(i, N) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[i] = mp(Mint(a), Mint(b));
	}
	segtree<U> seg(vec);
	while (Q--) {
		int t; scanf("%d", &t);
		if (t == 0) {
			int p, c, d;
			scanf("%d %d %d", &p, &c, &d);
			seg.modify(p, mp(Mint(c), Mint(d)));
		} else {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			auto f = seg.query(l, r);
			printf("%d\n", (f.fi * Mint(x) + f.se).v);
		}
	}

	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

