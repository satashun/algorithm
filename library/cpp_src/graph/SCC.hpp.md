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


# :heavy_check_mark: cpp_src/graph/SCC.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#899db7edb5841537da14f45d9b6032f9">cpp_src/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/graph/SCC.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 18:25:18+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

