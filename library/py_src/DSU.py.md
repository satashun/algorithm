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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: py_src/DSU.py

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#895f3d248130be399c7a2293f16f9fdc">py_src</a>
* <a href="{{ site.github.repository_url }}/blob/master/py_src/DSU.py">View this file on GitHub</a>
    - Last commit date: 2020-03-27 19:07:10+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class UnionFind():
	def __init__(self, n):
		self.n = n
		self.par = [-1] * n
		for i in range(0, n):
			self.par[i] = i
		self.rank = [0] * n

	def find(self, x):
		if self.par[x] < 0:
			return x
		else:
			self.par[x] = self.find(self.par[x])
			return self.par[x]

	def unite(self, x, y):
		x = self.find(x)
		y = self.find(y)

		if x == y:
			return 

			if self.rank[x] < self.rank[y]:
				x, y = y, x
		self.par[y] = x
		if self.rank[x] == self.rank[y]:
			self.rank[x] += 1

	def same(self, x, y):
		return self.find(x) == self.find(y)
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py", line 84, in bundle
    raise NotImplementedError
NotImplementedError

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

