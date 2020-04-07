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


# :heavy_check_mark: cpp_src/data_structure/fenwick.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0efeb1959dbc8f7e9170e2d5bfa803ae">cpp_src/data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/data_structure/fenwick.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-13 00:12:49+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n = 0) : n(_n), bit(n + 1) {}

	//sum of [0, i), 0 <= i <= n
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	//0 <= i < n
	void add(int i, T x) {
		++i;
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}

	//[l, r) 0 <= l < r < n
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}

	//not verified

	//smallest i, sum(i) >= w, none -> n + 1
	int lower_bound(int w) {
		if (w <= 0) return 0;
		int x = 0, l = 1;
		while (l * 2 <= n) l *= 2;

		for (int k = l; k > 0; k /= 2) {
			if (x + k <= n && bit[x + k] < w) {
				w -= bit[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/data_structure/fenwick.hpp"
template<class T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n = 0) : n(_n), bit(n + 1) {}

	//sum of [0, i), 0 <= i <= n
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	//0 <= i < n
	void add(int i, T x) {
		++i;
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}

	//[l, r) 0 <= l < r < n
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}

	//not verified

	//smallest i, sum(i) >= w, none -> n + 1
	int lower_bound(int w) {
		if (w <= 0) return 0;
		int x = 0, l = 1;
		while (l * 2 <= n) l *= 2;

		for (int k = l; k > 0; k /= 2) {
			if (x + k <= n && bit[x + k] < w) {
				w -= bit[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

