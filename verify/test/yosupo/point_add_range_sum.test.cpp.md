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


# :heavy_check_mark: test/yosupo/point_add_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_add_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 22:37:23+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/cpp_src/data_structure/fenwick.hpp.html">cpp_src/data_structure/fenwick.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
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
#include "../../cpp_src/data_structure/fenwick.hpp"
#undef call_from_test

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	BIT<ll> T(N);
	V<ll> a(N);
	rep(i, N) {
		scanf("%lld", &a[i]);
		T.add(i, a[i]);
	}
	while (Q--) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int p, x;
			scanf("%d %d", &p, &x);
			T.add(p, x);
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", T.sum(l, r));
		}
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_add_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
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
#line 1 "cpp_src/data_structure/fenwick.hpp"
template<class T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n = 0) : n(_n), bit(n + 1) {}

	//sum of [0, i), 0 <= i <= n
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	//0 <= i < n
	void add(int i, T x) {
		++i;
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}

	//[l, r) 0 <= l < r < n
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}

	//not verified

	//smallest i, sum(i) >= w, none -> n + 1
	int lower_bound(int w) {
		if (w <= 0) return 0;
		int x = 0, l = 1;
		while (l * 2 <= n) l *= 2;

		for (int k = l; k > 0; k /= 2) {
			if (x + k <= n && bit[x + k] < w) {
				w -= bit[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};
#line 49 "test/yosupo/point_add_range_sum.test.cpp"
#undef call_from_test

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	BIT<ll> T(N);
	V<ll> a(N);
	rep(i, N) {
		scanf("%lld", &a[i]);
		T.add(i, a[i]);
	}
	while (Q--) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int p, x;
			scanf("%d %d", &p, &x);
			T.add(p, x);
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", T.sum(l, r));
		}
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

