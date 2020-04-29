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


# :warning: cpp_src/math/matrix.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f80e2498998e03897cbfac19f068c09">cpp_src/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/math/matrix.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 02:45:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T>
struct Matrix : VV<D> {
    using Mat = Matrix<T>;
    int H() const { return int(size()); }
    int W() const { return int((*this)[0].size();) }

    Mat operator*(const Mat& a) const {
        int h = H(), w = W();
        int h2 = a.H(), w2 = a.W();
        assert(w == h2);
        Mat res(h, V<T>(w2));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w2; ++j) {
                for (int k = 0; k < w; ++k) {
                    res[i][j] += (*this)[i][k] * a[k][j];
                }
            }
        }
        return res;
    }

    Mat& operator*=(const Mat& r) { return *this = *this * r; }

    Mat pow(ll n) const {
        assert(H() == W());
        int h = H();
        Mat x = *this, res(h, V<T>(h));
        for (int i = 0; i < h; ++i) {
            res[i] = T(1);
        }
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/math/matrix.hpp"
template <class T>
struct Matrix : VV<D> {
    using Mat = Matrix<T>;
    int H() const { return int(size()); }
    int W() const { return int((*this)[0].size();) }

    Mat operator*(const Mat& a) const {
        int h = H(), w = W();
        int h2 = a.H(), w2 = a.W();
        assert(w == h2);
        Mat res(h, V<T>(w2));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w2; ++j) {
                for (int k = 0; k < w; ++k) {
                    res[i][j] += (*this)[i][k] * a[k][j];
                }
            }
        }
        return res;
    }

    Mat& operator*=(const Mat& r) { return *this = *this * r; }

    Mat pow(ll n) const {
        assert(H() == W());
        int h = H();
        Mat x = *this, res(h, V<T>(h));
        for (int i = 0; i < h; ++i) {
            res[i] = T(1);
        }
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

