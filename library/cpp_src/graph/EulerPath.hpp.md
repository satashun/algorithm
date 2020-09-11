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


# :warning: cpp_src/graph/EulerPath.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#899db7edb5841537da14f45d9b6032f9">cpp_src/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/graph/EulerPath.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 21:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Hierholzer algorithm
// https://codeforces.com/contest/508/submission/92099335

// directed
// destruct graph

template <class E>
V<int> EulerianPath(const int s, VV<E>& g) {
    auto dfs = [&](auto&& self, int u, V<int>& path) -> void {
        while (!g[u].empty()) {
            int v = g[u].back();  // E : int
            g[u].pop_back();
            self(self, v, path);
        }
        path.push_back(u);
    };
    V<int> path;
    dfs(dfs, s, path);
    reverse(path.begin(), path.end());
    return path;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/graph/EulerPath.hpp"
// Hierholzer algorithm
// https://codeforces.com/contest/508/submission/92099335

// directed
// destruct graph

template <class E>
V<int> EulerianPath(const int s, VV<E>& g) {
    auto dfs = [&](auto&& self, int u, V<int>& path) -> void {
        while (!g[u].empty()) {
            int v = g[u].back();  // E : int
            g[u].pop_back();
            self(self, v, path);
        }
        path.push_back(u);
    };
    V<int> path;
    dfs(dfs, s, path);
    reverse(path.begin(), path.end());
    return path;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

