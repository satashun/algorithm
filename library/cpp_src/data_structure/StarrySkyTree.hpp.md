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


# :warning: cpp_src/data_structure/StarrySkyTree.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0efeb1959dbc8f7e9170e2d5bfa803ae">cpp_src/data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/data_structure/StarrySkyTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-17 17:57:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const int SZ = (1 << 12);
const int inf;

struct starry_sky_tree {
    int all[SZ * 2], ma[SZ * 2];

    void init() {
        memset(all, 0, sizeof(all));
        memset(ma, 0, sizeof(ma));
    }

    void add(int a, int b, int x, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = max(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
    }

    int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) {
            return ma[k] + all[k];
        }

        int lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        int rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(lc, rc) + all[k];
    }

    int get() { return ma[0] + all[0]; }
} seg;

int sz;
const int INF = TEN(9);

struct starry_sky_tree {
    int all[1<<19], ma[1<<19], cnt[1<<19];

    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        rep(i, sz * 2) {
            all[i] = 0;
            ma[i] = 0;
            cnt[i] = 0;
        }
        for (int i = sz - 1; i < sz * 2 - 1; ++i) {
            cnt[i] = 1;
        }
        for (int i = sz - 1 + n; i < sz * 2 - 1; ++i) {
            ma[i] = INF;
        }
        for (int i = sz - 2; i >= 0; --i) {
            ma[i] = min(ma[i * 2 + 1], ma[i * 2 + 2]);
            cnt[i] = 0;
            if (ma[i] == ma[i * 2 + 1]) {
                cnt[i] += cnt[i * 2 + 1];
            }
            if (ma[i] == ma[i * 2 + 2]) {
                cnt[i] += cnt[i * 2 + 2];
            }           
        }
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = min(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
        cnt[k] = 0;
        if (ma[k] == ma[k * 2 + 1] + all[k * 2 + 1]) {
            cnt[k] += cnt[k * 2 + 1];
        }
        if (ma[k] == ma[k * 2 + 2] + all[k * 2 + 2]) {
            cnt[k] += cnt[k * 2 + 2];
        }        
    }

    pii get(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return mp(INF, 0);
        if (a <= l && r <= b) {
            return mp(ma[k] + all[k], cnt[k]);
        }

        pii lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        pii rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        int num = 0;
        int mini = min(lc.fi, rc.fi);
        if (mini == lc.fi) {
            num += lc.se;
        }
        if (mini == rc.fi) {
            num += rc.se;
        }
        return mp(mini + all[k], num);
    }
} seg;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/data_structure/StarrySkyTree.hpp"
const int SZ = (1 << 12);
const int inf;

struct starry_sky_tree {
    int all[SZ * 2], ma[SZ * 2];

    void init() {
        memset(all, 0, sizeof(all));
        memset(ma, 0, sizeof(ma));
    }

    void add(int a, int b, int x, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = max(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
    }

    int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) {
            return ma[k] + all[k];
        }

        int lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        int rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(lc, rc) + all[k];
    }

    int get() { return ma[0] + all[0]; }
} seg;

int sz;
const int INF = TEN(9);

struct starry_sky_tree {
    int all[1<<19], ma[1<<19], cnt[1<<19];

    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        rep(i, sz * 2) {
            all[i] = 0;
            ma[i] = 0;
            cnt[i] = 0;
        }
        for (int i = sz - 1; i < sz * 2 - 1; ++i) {
            cnt[i] = 1;
        }
        for (int i = sz - 1 + n; i < sz * 2 - 1; ++i) {
            ma[i] = INF;
        }
        for (int i = sz - 2; i >= 0; --i) {
            ma[i] = min(ma[i * 2 + 1], ma[i * 2 + 2]);
            cnt[i] = 0;
            if (ma[i] == ma[i * 2 + 1]) {
                cnt[i] += cnt[i * 2 + 1];
            }
            if (ma[i] == ma[i * 2 + 2]) {
                cnt[i] += cnt[i * 2 + 2];
            }           
        }
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = min(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
        cnt[k] = 0;
        if (ma[k] == ma[k * 2 + 1] + all[k * 2 + 1]) {
            cnt[k] += cnt[k * 2 + 1];
        }
        if (ma[k] == ma[k * 2 + 2] + all[k * 2 + 2]) {
            cnt[k] += cnt[k * 2 + 2];
        }        
    }

    pii get(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return mp(INF, 0);
        if (a <= l && r <= b) {
            return mp(ma[k] + all[k], cnt[k]);
        }

        pii lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        pii rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        int num = 0;
        int mini = min(lc.fi, rc.fi);
        if (mini == lc.fi) {
            num += lc.se;
        }
        if (mini == rc.fi) {
            num += rc.se;
        }
        return mp(mini + all[k], num);
    }
} seg;

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

