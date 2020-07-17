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


# :warning: cpp_src/graph/BipartiteMatching.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#899db7edb5841537da14f45d9b6032f9">cpp_src/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/graph/BipartiteMatching.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-17 17:36:15+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//O(NM)
struct bipartite_matching {
    int n;
    VV<int> g;
    V<int> match;
    V<bool> used;
    bipartite_matching() {}
    bipartite_matching(int n) : n(n), g(n), match(n), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool dfs(int v) {
        used[v] = true;

        for (int u : g[v]) {
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }

        return false;
    }

    int calc() {
        int res = 0;
        fill(match.begin(), match.end(), -1);

        for (int v = 0; v < n; ++v) {
            if (match[v] < 0) {
                fill(used.begin(), used.end(), false);
                res += dfs(v);
            }
        }
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/graph/BipartiteMatching.hpp"
//O(NM)
struct bipartite_matching {
    int n;
    VV<int> g;
    V<int> match;
    V<bool> used;
    bipartite_matching() {}
    bipartite_matching(int n) : n(n), g(n), match(n), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool dfs(int v) {
        used[v] = true;

        for (int u : g[v]) {
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }

        return false;
    }

    int calc() {
        int res = 0;
        fill(match.begin(), match.end(), -1);

        for (int v = 0; v < n; ++v) {
            if (match[v] < 0) {
                fill(used.begin(), used.end(), false);
                res += dfs(v);
            }
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

