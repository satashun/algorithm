---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class UnionFind():\n\tdef __init__(self, n):\n\t\tself.n = n\n\t\tself.par\
    \ = [-1] * n\n\t\tfor i in range(0, n):\n\t\t\tself.par[i] = i\n\t\tself.rank\
    \ = [0] * n\n\n\tdef find(self, x):\n\t\tif self.par[x] < 0:\n\t\t\treturn x\n\
    \t\telse:\n\t\t\tself.par[x] = self.find(self.par[x])\n\t\t\treturn self.par[x]\n\
    \n\tdef unite(self, x, y):\n\t\tx = self.find(x)\n\t\ty = self.find(y)\n\n\t\t\
    if x == y:\n\t\t\treturn \n\n\t\t\tif self.rank[x] < self.rank[y]:\n\t\t\t\tx,\
    \ y = y, x\n\t\tself.par[y] = x\n\t\tif self.rank[x] == self.rank[y]:\n\t\t\t\
    self.rank[x] += 1\n\n\tdef same(self, x, y):\n\t\treturn self.find(x) == self.find(y)"
  dependsOn: []
  isVerificationFile: false
  path: py_src/DSU.py
  requiredBy: []
  timestamp: '2020-03-27 19:07:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: py_src/DSU.py
layout: document
redirect_from:
- /library/py_src/DSU.py
- /library/py_src/DSU.py.html
title: py_src/DSU.py
---
