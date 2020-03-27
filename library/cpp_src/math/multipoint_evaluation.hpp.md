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


# :warning: cpp_src/math/multipoint_evaluation.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f80e2498998e03897cbfac19f068c09">cpp_src/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/math/multipoint_evaluation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 23:24:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class D>
struct MultiEval {
	using P = MultiEval*;
	P lc, rc;
	V<D> xs;
	int sz;
	Poly<D> dpol;

	const int B = 100;

	MultiEval(const V<D>& _xs, int l, int r) : sz(r - l) {
		if (r - l <= B) {
			xs = {_xs.begin() + l, _xs.begin() + r};
			dpol = {{1}};
			for (auto x : xs) {
				dpol *= {-x, 1};
			}
			return ;
		}
		lc = new MultiEval(_xs, l, (l + r) / 2);
		rc = new MultiEval(_xs, (l + r) / 2, r);
		dpol = lc->dpol * rc->dpol;
	}

	MultiEval(const V<D>& xs) : MultiEval(xs, 0, xs.size()) {}

	void eval(const Poly<D>& poly, V<D>& res) {
		auto p = poly % dpol;
		if (sz <= B) {
			for (auto x : xs) {
				res.pb(p.eval(x));
			}
			return ;
		}
		lc->eval(p, res);
		rc->eval(p, res);
	}

	V<D> eval(const Poly<D>& poly) {
		V<D> res;
		eval(poly, res);
		return res;
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/math/multipoint_evaluation.hpp"
template<class D>
struct MultiEval {
	using P = MultiEval*;
	P lc, rc;
	V<D> xs;
	int sz;
	Poly<D> dpol;

	const int B = 100;

	MultiEval(const V<D>& _xs, int l, int r) : sz(r - l) {
		if (r - l <= B) {
			xs = {_xs.begin() + l, _xs.begin() + r};
			dpol = {{1}};
			for (auto x : xs) {
				dpol *= {-x, 1};
			}
			return ;
		}
		lc = new MultiEval(_xs, l, (l + r) / 2);
		rc = new MultiEval(_xs, (l + r) / 2, r);
		dpol = lc->dpol * rc->dpol;
	}

	MultiEval(const V<D>& xs) : MultiEval(xs, 0, xs.size()) {}

	void eval(const Poly<D>& poly, V<D>& res) {
		auto p = poly % dpol;
		if (sz <= B) {
			for (auto x : xs) {
				res.pb(p.eval(x));
			}
			return ;
		}
		lc->eval(p, res);
		rc->eval(p, res);
	}

	V<D> eval(const Poly<D>& poly) {
		V<D> res;
		eval(poly, res);
		return res;
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

