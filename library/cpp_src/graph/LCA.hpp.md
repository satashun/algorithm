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


# :x: cpp_src/graph/LCA.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#899db7edb5841537da14f45d9b6032f9">cpp_src/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/graph/LCA.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-12 22:31:33+09:00




## Verified with

* :x: <a href="../../../verify/test/yosupo/lca.test.cpp.html">test/yosupo/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

