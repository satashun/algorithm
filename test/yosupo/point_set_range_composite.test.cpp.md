---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../cpp_src/math/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
    \ T> using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i,n) rep2(i,0,n)\n\
    #define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define ALL(c) (c).begin(),(c).end()\n\
    \n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" <<\
    \ (x) << endl\n#else \n#define dump(x) true\n#endif\n\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class T, class U> void\
    \ chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class T, class U> void\
    \ chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate<class T, class U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& p) {\n\tos<<\"(\"<<p.first<<\"\
    ,\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n\tos<<\"{\";\n\trep(i, v.size()) {\n\t\tif (i) os<<\"\
    ,\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\treturn os;\n}\n\n#define call_from_test\n\
    #include \"../../cpp_src/math/modint.hpp\"\n#undef call_from_test\n\nusing Mint\
    \ = ModInt<998244353>;\n\n//index of root = 1\n\ntemplate<class U>\nstruct segtree\
    \ {\n\tusing T = typename U::T;\n\tint sz;\n\tV<T> dat;\n\n\tsegtree(const V<T>&\
    \ a) {\n\t\tint n = a.size();\n\t\tsz = 1;\n\t\twhile (sz < n) sz <<= 1;\n\t\t\
    dat.assign(sz * 2, U::id());\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tdat[sz\
    \ + i] = a[i];\n\t\t}\n\t\tfor (int i = sz - 1; i >= 1; --i) {\n\t\t\tupd(i);\n\
    \t\t}\n\t}\n\n\tvoid upd(int p) {\n\t\tdat[p] = U::op(dat[p<<1], dat[p<<1|1]);\n\
    \t}\n\n\tvoid build() {\n\t\tfor (int i = sz - 1; i > 0; --i) {\n\t\t\tdat[i]\
    \ = U::op(dat[i<<1], dat[i<<1|1]);\t\t\n\t\t}\n\t}\n\n\tvoid modify(int p, T v)\
    \ {\n\t\tp += sz;\n\t\tdat[p] = v;\n\t\twhile (p >>= 1) {\n\t\t\tdat[p] = U::op(dat[p<<1],\
    \ dat[p<<1|1]);\n\t\t}\n\t}\n\n\t//[l, r)\n\n\tT query(int l, int r) {\n\t\tT\
    \ lval = U::id(), rval = U::id();\n\t\tint res = 0;\n\t\tfor (l += sz, r += sz;\
    \ l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) lval = U::op(lval, dat[l++]);\n\
    \t\t\tif (r & 1) rval = U::op(dat[--r], rval);\n\t\t}\n\t\treturn U::op(lval,\
    \ rval);\n\t}\n};\n\nconst int INF = TEN(9) + 10;\n\nstruct U {\n    using T =\
    \ pair<Mint, Mint>;\n    static T id() { return mp(Mint(1), Mint(0)); }\n    static\
    \ T op(const T& a, const T& b) {\n    \treturn mp(a.first * b.first, a.second\
    \ * b.first + b.second);\n    }\n};\n\nint main() {\n\tint N, Q; scanf(\"%d %d\"\
    , &N, &Q);\n\tV<pair<Mint, Mint>> vec(N);\n\n\trep(i, N) {\n\t\tint a, b;\n\t\t\
    scanf(\"%d %d\", &a, &b);\n\t\tvec[i] = mp(Mint(a), Mint(b));\n\t}\n\tsegtree<U>\
    \ seg(vec);\n\twhile (Q--) {\n\t\tint t; scanf(\"%d\", &t);\n\t\tif (t == 0) {\n\
    \t\t\tint p, c, d;\n\t\t\tscanf(\"%d %d %d\", &p, &c, &d);\n\t\t\tseg.modify(p,\
    \ mp(Mint(c), Mint(d)));\n\t\t} else {\n\t\t\tint l, r, x;\n\t\t\tscanf(\"%d %d\
    \ %d\", &l, &r, &x);\n\t\t\tauto f = seg.query(l, r);\n\t\t\tprintf(\"%d\\n\"\
    , (f.fi * Mint(x) + f.se).v);\n\t\t}\n\t}\n\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
