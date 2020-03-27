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


# :warning: cpp_src/string/Z_algorithm.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1af93c576686231cc039edb77ac3381f">cpp_src/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/cpp_src/string/Z_algorithm.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-14 23:17:55+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<int> Z_algo(const string &S) {
	vector<int> A(S.size());
	A[0] = S.size();
	int i = 1, j = 0;
	while (i < S.size()) {
		while (i+j < S.size() && S[j] == S[i+j]) ++j;
		A[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
		i += k; j -= k;
	}
	return A;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cpp_src/string/Z_algorithm.hpp"
vector<int> Z_algo(const string &S) {
	vector<int> A(S.size());
	A[0] = S.size();
	int i = 1, j = 0;
	while (i < S.size()) {
		while (i+j < S.size() && S[j] == S[i+j]) ++j;
		A[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
		i += k; j -= k;
	}
	return A;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

