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


# :heavy_check_mark: test/yosupo/staticrmq.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/staticrmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 22:37:23+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/cpp_src/data_structure/segment_tree.hpp.html">cpp_src/data_structure/segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
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
#include "../../cpp_src/data_structure/segment_tree.hpp"
#undef call_from_test

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	V<ll> a(N);
	rep(i, N) {
		scanf("%d", &a[i]);
	}
	segtree<U> seg(a);
	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", seg.query(l, r));
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/staticrmq.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
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
#line 1 "cpp_src/data_structure/segment_tree.hpp"
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

	void modify(int p, int value) {
		p += sz;
		dat[p] = value;
		while (p >>= 1) {
			dat[p] = U::op(dat[p<<1], dat[p<<1|1]);
		}
	}

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
    using T = ll;
    static T id() { return INF; }
    static T op(const T& a, const T& b) {
    	return min(a, b);
    }
};
#line 49 "test/yosupo/staticrmq.test.cpp"
#undef call_from_test

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	V<ll> a(N);
	rep(i, N) {
		scanf("%d", &a[i]);
	}
	segtree<U> seg(a);
	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", seg.query(l, r));
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

