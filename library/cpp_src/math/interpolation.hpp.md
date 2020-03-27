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


# :warning: cpp_src/math/interpolation.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f80e2498998e03897cbfac19f068c09">cpp_src/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/math/interpolation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-11 22:01:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class D>
struct PolyBuf {
	const V<D> &xs;
	PolyBuf(const V<D>& xs) : xs(xs) {}
	using P = Poly<D>;
	map<pii, P> buf;
	const P& get(int l, int r) {
		if (buf.count(mp(l, r))) {
			return buf[mp(l, r)];
		}
		if (r - l == 1) {
			return buf[mp(l, r)] = P{-xs[l], 1};
		}
		return buf[mp(l, r)] = get(l, (l + r) / 2) * get((l + r) / 2, r);
	}
};

template<class D>
Poly<D> interpolate(const V<D>& xs, const V<D>& ys) {
	MultiEval<D> U(xs);
	auto vd = U.dpol.diff();
	auto res = U.eval(vd);
	PolyBuf<D> buf(xs);

	function<Poly<D>(int,int)>rec=[&](int l, int r) {
		if (r - l == 1) {
			return Poly<D>{ys[l] / res[l]};
		}
		int m = (l + r) / 2;
		return rec(l, m) * buf.get(m, r) + rec(m, r) * buf.get(l, m);
	};
	return rec(0, xs.size());
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/math/interpolation.hpp"
template<class D>
struct PolyBuf {
	const V<D> &xs;
	PolyBuf(const V<D>& xs) : xs(xs) {}
	using P = Poly<D>;
	map<pii, P> buf;
	const P& get(int l, int r) {
		if (buf.count(mp(l, r))) {
			return buf[mp(l, r)];
		}
		if (r - l == 1) {
			return buf[mp(l, r)] = P{-xs[l], 1};
		}
		return buf[mp(l, r)] = get(l, (l + r) / 2) * get((l + r) / 2, r);
	}
};

template<class D>
Poly<D> interpolate(const V<D>& xs, const V<D>& ys) {
	MultiEval<D> U(xs);
	auto vd = U.dpol.diff();
	auto res = U.eval(vd);
	PolyBuf<D> buf(xs);

	function<Poly<D>(int,int)>rec=[&](int l, int r) {
		if (r - l == 1) {
			return Poly<D>{ys[l] / res[l]};
		}
		int m = (l + r) / 2;
		return rec(l, m) * buf.get(m, r) + rec(m, r) * buf.get(l, m);
	};
	return rec(0, xs.size());
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

