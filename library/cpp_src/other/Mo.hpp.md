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


# :warning: cpp_src/other/Mo.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3a410910d29f06f5e038fad6075af5c6">cpp_src/other</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/other/Mo.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-27 19:07:10+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Mo {
	V<int> left, right, order;
	V<bool> v;
	int Bsize, nl, nr, ptr;

	Mo(int n) : Bsize((int)sqrt(n+1)), nl(0), nr(0), ptr(0), v(n) {}

	//[l, r)
	void insert(int l, int r) {
		left.push_back(l);
		right.push_back(r);
	}

	void build() {
		order.resize(left.size());
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int a, int b) {
			if (left[a] / Bsize != left[b] / Bsize) return left[a] < left[b];
			else return right[a] < right[b];
		});
	}

	//return next event id
	int proceed() {
		if (ptr == order.size()) return -1;
		int id = order[ptr];
		while (nl > left[id]) query(--nl);
		while (nr < right[id]) query(nr++);
		while (nl < left[id]) query(nl++);
		while (nr > right[id]) query(--nr);
		return (order[ptr++]);
	}

	void query(int p) {
		v[p] = !v[p];
		if (v[p]) add(p);
		else del(p);
	}

	void add(int p) {
	}

	void del(int p) {
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/other/Mo.hpp"
struct Mo {
	V<int> left, right, order;
	V<bool> v;
	int Bsize, nl, nr, ptr;

	Mo(int n) : Bsize((int)sqrt(n+1)), nl(0), nr(0), ptr(0), v(n) {}

	//[l, r)
	void insert(int l, int r) {
		left.push_back(l);
		right.push_back(r);
	}

	void build() {
		order.resize(left.size());
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int a, int b) {
			if (left[a] / Bsize != left[b] / Bsize) return left[a] < left[b];
			else return right[a] < right[b];
		});
	}

	//return next event id
	int proceed() {
		if (ptr == order.size()) return -1;
		int id = order[ptr];
		while (nl > left[id]) query(--nl);
		while (nr < right[id]) query(nr++);
		while (nl < left[id]) query(nl++);
		while (nr > right[id]) query(--nr);
		return (order[ptr++]);
	}

	void query(int p) {
		v[p] = !v[p];
		if (v[p]) add(p);
		else del(p);
	}

	void add(int p) {
	}

	void del(int p) {
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

