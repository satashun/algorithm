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


# :warning: cpp_src/math/typical_mod_operation.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f80e2498998e03897cbfac19f068c09">cpp_src/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/math/typical_mod_operation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-12 13:43:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const int maxv = 1000010;

Mint fact[maxv], finv[maxv], inv[maxv];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxv; ++i) {
        fact[i] = fact[i-1] * i;
    }

    finv[maxv-1] = fact[maxv-1].inv();
    for (int i = maxv - 2; i >= 0; --i) {
        finv[i] = finv[i+1] * (i+1);
    }

    for (int i = 1; i < maxv; ++i) {
        inv[i] = finv[i] * fact[i-1];
    }
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return fact[n] * finv[r] * finv[n-r];
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/math/typical_mod_operation.hpp"
const int maxv = 1000010;

Mint fact[maxv], finv[maxv], inv[maxv];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxv; ++i) {
        fact[i] = fact[i-1] * i;
    }

    finv[maxv-1] = fact[maxv-1].inv();
    for (int i = maxv - 2; i >= 0; --i) {
        finv[i] = finv[i+1] * (i+1);
    }

    for (int i = 1; i < maxv; ++i) {
        inv[i] = finv[i] * fact[i-1];
    }
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return fact[n] * finv[r] * finv[n-r];
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

