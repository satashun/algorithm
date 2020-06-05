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


# :warning: cpp_src/graph/Dinic.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#899db7edb5841537da14f45d9b6032f9">cpp_src/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/graph/Dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 01:31:45+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// O(V^2 E)
struct Dinic {
    using F = ll;
    static constexpr F INF = numeric_limits<F>::max();

    struct Edge {
        int to, rev;
        F cap;
        Edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev){};
    };

    using E = Edge;

    VV<E> g;
    V<int> level, iter;

    Dinic() {}
    Dinic(int n) : g(n), level(n), iter(n) {}

    void add_edge(int from, int to, F cap) {
        g[from].emplace_back(to, cap, (int)g[to].size());
        g[to].emplace_back(from, 0, (int)g[from].size() - 1);
    }

    void bfs(int s) {
        fill(ALL(level), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    F dfs(int v, int t, F f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                F d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    F max_flow(int s, int t) {
        F flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(ALL(iter), 0);
            F f;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/graph/Dinic.hpp"
// O(V^2 E)
struct Dinic {
    using F = ll;
    static constexpr F INF = numeric_limits<F>::max();

    struct Edge {
        int to, rev;
        F cap;
        Edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev){};
    };

    using E = Edge;

    VV<E> g;
    V<int> level, iter;

    Dinic() {}
    Dinic(int n) : g(n), level(n), iter(n) {}

    void add_edge(int from, int to, F cap) {
        g[from].emplace_back(to, cap, (int)g[to].size());
        g[to].emplace_back(from, 0, (int)g[from].size() - 1);
    }

    void bfs(int s) {
        fill(ALL(level), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    F dfs(int v, int t, F f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                F d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    F max_flow(int s, int t) {
        F flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(ALL(iter), 0);
            F f;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

