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


# :heavy_check_mark: test/yosupo/bipartitematching.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/bipartitematching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-17 17:36:15+09:00


* see: <a href="https://judge.yosupo.jp/problem/bipartitematching">https://judge.yosupo.jp/problem/bipartitematching</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/cpp_src/graph/Dinic.hpp.html">cpp_src/graph/Dinic.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

#define call_from_test
#include "../../cpp_src/graph/Dinic.hpp"
#undef call_from_test

int main() {
    int L, R, M;
    scanf("%d %d %d", &L, &R, &M);
    int n = L + R + 2;
    int s = n - 2, t = n - 1;
    Dinic g(n);
    rep(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        g.add_edge(a, b + L, 1);
    }
    rep(i, L) g.add_edge(s, i, 1);
    rep(i, R) g.add_edge(i + L, t, 1);

    int K = g.max_flow(s, t);

    printf("%d\n", K);
    rep(i, L) {
        int mt = -1;
        for (auto e : g.g[i])
            if (e.to >= L && e.to < L + R && e.cap == 0) {
                mt = e.to;
            }
        if (mt != -1) {
            printf("%d %d\n", i, mt - L);
        }
    }

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/bipartitematching.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

#define call_from_test
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
#line 68 "test/yosupo/bipartitematching.test.cpp"
#undef call_from_test

int main() {
    int L, R, M;
    scanf("%d %d %d", &L, &R, &M);
    int n = L + R + 2;
    int s = n - 2, t = n - 1;
    Dinic g(n);
    rep(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        g.add_edge(a, b + L, 1);
    }
    rep(i, L) g.add_edge(s, i, 1);
    rep(i, R) g.add_edge(i + L, t, 1);

    int K = g.max_flow(s, t);

    printf("%d\n", K);
    rep(i, L) {
        int mt = -1;
        for (auto e : g.g[i])
            if (e.to >= L && e.to < L + R && e.cap == 0) {
                mt = e.to;
            }
        if (mt != -1) {
            printf("%d %d\n", i, mt - L);
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

