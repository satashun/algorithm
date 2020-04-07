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


# :warning: cpp_src/other/FWT.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3a410910d29f06f5e038fad6075af5c6">cpp_src/other</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/other/FWT.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 22:26:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//vector size : power of 2

template<class T>
void and_fwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = x + y;
            }
        }
    }
}

template<class T>
void and_ifwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = x - y;
            }
        }
    }
}

template<class T>
void xor_fwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = x + y;
                f[i+j+d] = x - y;
            }
        }
    }
}

template<class T>
void xor_ifwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = (x + y) * i2;
                f[i+j+d] = (x - y) * i2;
            }
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/other/FWT.hpp"
//vector size : power of 2

template<class T>
void and_fwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = x + y;
            }
        }
    }
}

template<class T>
void and_ifwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = x - y;
            }
        }
    }
}

template<class T>
void xor_fwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = x + y;
                f[i+j+d] = x - y;
            }
        }
    }
}

template<class T>
void xor_ifwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                Mint x = f[i+j], y = f[i+j+d];
                f[i+j] = (x + y) * i2;
                f[i+j+d] = (x - y) * i2;
            }
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

