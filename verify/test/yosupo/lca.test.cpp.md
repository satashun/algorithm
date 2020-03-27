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


# :heavy_check_mark: test/yosupo/lca.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-28 03:00:41+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/cpp_src/graph/LCA.hpp.html">cpp_src/graph/LCA.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
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
#include "../../cpp_src/graph/LCA.hpp"
#undef call_from_test

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	V<int> p(N);
	VV<int> g(N);
	for (int i = 1; i < N; ++i) {
		scanf("%d", &p[i]);
		g[p[i]].pb(i);
	}
	LCA<int> lca(g, 0);
	while (Q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int v = lca.query(a, b);
		printf("%d\n", v);
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/lca.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
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
#line 1 "cpp_src/graph/LCA.hpp"
//E : int or edge class

template<class E>
struct LCA {
	VV<int> anc;
	V<int> dep;
	int lg;
	const VV<E>& g;

	LCA(const VV<E>& g, int root) : g(g) {
		int n = g.size();
		lg = 1;
		while ((1 << lg) < n) lg++;
		anc = VV<int>(lg, V<int>(n, -1));
		dep = V<int>(n);
		dfs(root, -1, 0);

		for (int i = 1; i < lg; i++) {
			for (int j = 0; j < n; j++) {
				anc[i][j] = (anc[i - 1][j] == -1) ? -1 : anc[i - 1][anc[i - 1][j]];
			}
		}		
	}

	void dfs(int v, int p, int d) {
		anc[0][v] = p;
		dep[v] = d;
		for (auto e : g[v]) {
			int to = e;
			if (to == p) continue;
			dfs(to, v, d + 1);
		}
	}

	int query(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		int df = dep[u] - dep[v];
		for (int i = lg - 1; i >= 0; --i) {
			if ((df >> i) & 1) {
				df -= (1 << i);
				u = anc[i][u];
			}
		}
		if (u == v) return u;
		for (int i = lg - 1; i >= 0; --i) {
			if (anc[i][u] != anc[i][v]) {
				u = anc[i][u];
				v = anc[i][v];
			}
		}
		return anc[0][u];
	}
};
#line 50 "test/yosupo/lca.test.cpp"
#undef call_from_test

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	V<int> p(N);
	VV<int> g(N);
	for (int i = 1; i < N; ++i) {
		scanf("%d", &p[i]);
		g[p[i]].pb(i);
	}
	LCA<int> lca(g, 0);
	while (Q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int v = lca.query(a, b);
		printf("%d\n", v);
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

