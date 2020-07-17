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


# :warning: cpp_src/string/RollingHash.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1af93c576686231cc039edb77ac3381f">cpp_src/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/string/RollingHash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-17 17:57:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// from ei1333

template <unsigned mod>
struct RollingHash {
    vector<unsigned> hashed, power;

    inline unsigned mul(unsigned a, unsigned b) const {
        unsigned long long x = (unsigned long long)a * b;
        unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
        asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod));
        return m;
    }

    RollingHash(const string &s, unsigned base = 10007) {
        int sz = (int)s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for (int i = 0; i < sz; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    unsigned get(int l, int r) const {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    unsigned connect(unsigned h1, int h2, int h2len) const {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod) ret -= mod;
        return ret;
    }

    int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return (low);
    }
};

using RH = RollingHash<1000000007>;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/string/RollingHash.hpp"
// from ei1333

template <unsigned mod>
struct RollingHash {
    vector<unsigned> hashed, power;

    inline unsigned mul(unsigned a, unsigned b) const {
        unsigned long long x = (unsigned long long)a * b;
        unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
        asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod));
        return m;
    }

    RollingHash(const string &s, unsigned base = 10007) {
        int sz = (int)s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for (int i = 0; i < sz; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    unsigned get(int l, int r) const {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    unsigned connect(unsigned h1, int h2, int h2len) const {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod) ret -= mod;
        return ret;
    }

    int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return (low);
    }
};

using RH = RollingHash<1000000007>;

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

