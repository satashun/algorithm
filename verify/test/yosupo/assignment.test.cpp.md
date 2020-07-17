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


# :heavy_check_mark: test/yosupo/assignment.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/assignment.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-17 17:36:15+09:00


* see: <a href="https://judge.yosupo.jp/problem/assignment">https://judge.yosupo.jp/problem/assignment</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
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
#define ALL(c) (c).begin(), (c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define dump(x) true
#endif

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

/*
#define call_from_test
#include "../../cpp_src/data_structure/unionfind.hpp"
#undef call_from_test
*/

template <class C, class D>  // capacity, distance
struct MinCostFlow {
    struct edge {
        int to, rev;
        C cap;
        D cost;
        edge(int to, C cap, D cost, int rev)
            : to(to), cap(cap), cost(cost), rev(rev){};
    };

    using E = edge;

    const D INF = numeric_limits<D>::max() / D(3);

    int n;
    VV<E> g;
    V<D> h, dst;
    V<int> prevv, preve;

    MinCostFlow(int n) : n(n), g(n), h(n), dst(n), prevv(n), preve(n) {}

    void add_edge(int f, int t, C cap, D cost) {
        g[f].emplace_back(t, cap, cost, (int)g[t].size());
        g[t].emplace_back(f, 0, -cost, (int)g[f].size() - 1);
    }

    void init_negative(int s) {
        fill(h.begin(), h.end(), INF);
        h[s] = 0;
        for (int t = 0; t < n; ++t) {
            for (int i = 0; i < n; ++i) {
                for (auto e : g[i]) {
                    if (!e.cap || h[i] == INF) continue;
                    h[e.to] = min(h[e.to], h[i] + e.cost);
                }
            }
        }
    }

    D exec(int s, int t, C f) {
        D res = 0;
        using Data = pair<D, int>;

        while (f > 0) {
            priority_queue<Data, vector<Data>, greater<Data>> que;
            fill(dst.begin(), dst.end(), INF);
            dst[s] = 0;
            que.push(Data(0, s));

            while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int v = p.se;
                if (dst[v] < p.fi) continue;

                rep(i, g[v].size()) {
                    auto e = g[v][i];
                    D nd = dst[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dst[e.to] > nd) {
                        dst[e.to] = nd;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(Data(dst[e.to], e.to));
                    }
                }
            }

            if (dst[t] == INF) return D(-1);
            rep(i, n) h[i] += dst[i];

            C d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, g[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge& e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;
    int N = n * 2 + 2;
    int s = N - 2, t = N - 1;
    MinCostFlow<ll, ll> mcf(N);
    rep(i, n) {
        rep(j, n) {
            int x;
            cin >> x;
            mcf.add_edge(i, j + n, 1, x);
        }
        mcf.add_edge(s, i, 1, 0);
        mcf.add_edge(i + n, t, 1, 0);
    }
    mcf.init_negative(s);
    ll X = mcf.exec(s, t, n);
    cout << X << endl;
    rep(i, N) {
        for (auto e : mcf.g[i]) {
            if (e.to >= n && e.to < n * 2 && e.cap == 0) {
                cout << e.to - n << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/assignment.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
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
#define ALL(c) (c).begin(), (c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define dump(x) true
#endif

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

/*
#define call_from_test
#include "../../cpp_src/data_structure/unionfind.hpp"
#undef call_from_test
*/

template <class C, class D>  // capacity, distance
struct MinCostFlow {
    struct edge {
        int to, rev;
        C cap;
        D cost;
        edge(int to, C cap, D cost, int rev)
            : to(to), cap(cap), cost(cost), rev(rev){};
    };

    using E = edge;

    const D INF = numeric_limits<D>::max() / D(3);

    int n;
    VV<E> g;
    V<D> h, dst;
    V<int> prevv, preve;

    MinCostFlow(int n) : n(n), g(n), h(n), dst(n), prevv(n), preve(n) {}

    void add_edge(int f, int t, C cap, D cost) {
        g[f].emplace_back(t, cap, cost, (int)g[t].size());
        g[t].emplace_back(f, 0, -cost, (int)g[f].size() - 1);
    }

    void init_negative(int s) {
        fill(h.begin(), h.end(), INF);
        h[s] = 0;
        for (int t = 0; t < n; ++t) {
            for (int i = 0; i < n; ++i) {
                for (auto e : g[i]) {
                    if (!e.cap || h[i] == INF) continue;
                    h[e.to] = min(h[e.to], h[i] + e.cost);
                }
            }
        }
    }

    D exec(int s, int t, C f) {
        D res = 0;
        using Data = pair<D, int>;

        while (f > 0) {
            priority_queue<Data, vector<Data>, greater<Data>> que;
            fill(dst.begin(), dst.end(), INF);
            dst[s] = 0;
            que.push(Data(0, s));

            while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int v = p.se;
                if (dst[v] < p.fi) continue;

                rep(i, g[v].size()) {
                    auto e = g[v][i];
                    D nd = dst[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dst[e.to] > nd) {
                        dst[e.to] = nd;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(Data(dst[e.to], e.to));
                    }
                }
            }

            if (dst[t] == INF) return D(-1);
            rep(i, n) h[i] += dst[i];

            C d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, g[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge& e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;
    int N = n * 2 + 2;
    int s = N - 2, t = N - 1;
    MinCostFlow<ll, ll> mcf(N);
    rep(i, n) {
        rep(j, n) {
            int x;
            cin >> x;
            mcf.add_edge(i, j + n, 1, x);
        }
        mcf.add_edge(s, i, 1, 0);
        mcf.add_edge(i + n, t, 1, 0);
    }
    mcf.init_negative(s);
    ll X = mcf.exec(s, t, n);
    cout << X << endl;
    rep(i, N) {
        for (auto e : mcf.g[i]) {
            if (e.to >= n && e.to < n * 2 && e.cap == 0) {
                cout << e.to - n << " ";
            }
        }
    }
    cout << endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

