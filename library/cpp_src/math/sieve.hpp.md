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


# :warning: cpp_src/math/sieve.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f80e2498998e03897cbfac19f068c09">cpp_src/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/math/sieve.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-06 01:21:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://cp-algorithms.com/algebra/prime-sieve-linear.html

const int maxv = 10000010;
// lowest prime factor
int lp[maxv];
bool pri[maxv];
vector<int> pr;

void linear_sive() {
    for (int i = 2; i < maxv; ++i) pri[i] = true;
    for (int i = 2; i < maxv; ++i) {
        if (pri[i]) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0;
             j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < maxv; ++j) {
            pri[i * pr[j]] = false;
            lp[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/math/sieve.hpp"
//https://cp-algorithms.com/algebra/prime-sieve-linear.html

const int maxv = 10000010;
// lowest prime factor
int lp[maxv];
bool pri[maxv];
vector<int> pr;

void linear_sive() {
    for (int i = 2; i < maxv; ++i) pri[i] = true;
    for (int i = 2; i < maxv; ++i) {
        if (pri[i]) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0;
             j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < maxv; ++j) {
            pri[i * pr[j]] = false;
            lp[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

