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


# :heavy_check_mark: test/yosupo/scc.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/scc.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 18:25:18+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/cpp_src/graph/SCC.hpp.html">cpp_src/graph/SCC.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

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
#include "../../cpp_src/graph/SCC.hpp"
#undef call_from_test

int main() {
	int N, M; scanf("%d %d", &N, &M);
	SCC scc(N);
	rep(i, M) {
		int a, b;
		scanf("%d %d", &a, &b);
		scc.add_edge(a, b);
	}
	auto v = scc.calc();
	printf("%d\n", v.size());
	rep(i, v.size()) {
		auto &vec = v[i];
		int sz = vec.size();
		printf("%d", sz);
		for (int j = 0; j < vec.size(); ++j) {
			printf(" %d", vec[j]);
		}
		puts("");
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/scc.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

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
#line 1 "cpp_src/graph/SCC.hpp"
struct SCC {
    int n;
    VV<int> g, rg;
    V<int> vs, cmp;
    V<bool> vis;

    SCC(){}
    SCC(int n) : n(n) {
        g = rg = VV<int>(n);
        vs = cmp = V<int>(n);
        vis = V<bool>(n);
    }

    void add_edge(int from, int to) {
        g[from].push_back(to);
        rg[to].push_back(from);
    }

    void dfs(int v) {
        vis[v] = true;

        for (int to : g[v]) {
            if (!vis[to]) {
                dfs(to);
            }
        }

        vs.push_back(v);
    }

    void rdfs(int v, int k, V<int>& vec) {
        vis[v] = true;
        cmp[v] = k;
        vec.push_back(v);

        for (int to : rg[v]) {
            if (!vis[to]) {
                rdfs(to, k, vec);
            }
        }
    }

    VV<int> calc() {
        rep(v, n) if (!vis[v]) dfs(v);

        fill(vis.begin(), vis.end(), false);

        int k = 0;
        reverse(vs.begin(), vs.end());

        VV<int> vcomp;

        for (int v : vs) {
            if (!vis[v]) {
                V<int> vec;
                rdfs(v, k++, vec);
                vcomp.push_back(vec);
            }
        }

        return vcomp;
    }
};
#line 50 "test/yosupo/scc.test.cpp"
#undef call_from_test

int main() {
	int N, M; scanf("%d %d", &N, &M);
	SCC scc(N);
	rep(i, M) {
		int a, b;
		scanf("%d %d", &a, &b);
		scc.add_edge(a, b);
	}
	auto v = scc.calc();
	printf("%d\n", v.size());
	rep(i, v.size()) {
		auto &vec = v[i];
		int sz = vec.size();
		printf("%d", sz);
		for (int j = 0; j < vec.size(); ++j) {
			printf(" %d", vec[j]);
		}
		puts("");
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
