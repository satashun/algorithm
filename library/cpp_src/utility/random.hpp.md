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


# :warning: cpp_src/utility/random.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d4e24500d23f47b8d075758221d17bd2">cpp_src/utility</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/utility/random.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-06 01:21:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
ll rand_int(ll l, ll r) {  //[l,r]
    static random_device rd;
    static mt19937 gen(rd());
    // static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}

// Fisher–Yates
template <class T>
vector<T> random_perm(vector<T> vec) {
    vector<T> res;
    rep(i, vec.size()) {
        res.pb(vec[i]);
        int j = rand_int(0, i);
        swap(res[j], res[i]);
    }
    return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/utility/random.hpp"
ll rand_int(ll l, ll r) {  //[l,r]
    static random_device rd;
    static mt19937 gen(rd());
    // static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}

// Fisher–Yates
template <class T>
vector<T> random_perm(vector<T> vec) {
    vector<T> res;
    rep(i, vec.size()) {
        res.pb(vec[i]);
        int j = rand_int(0, i);
        swap(res[j], res[i]);
    }
    return res;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

