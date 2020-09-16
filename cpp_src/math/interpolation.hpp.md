---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/math/interpolation.hpp\"\ntemplate<class D>\nstruct\
    \ PolyBuf {\n\tconst V<D> &xs;\n\tPolyBuf(const V<D>& xs) : xs(xs) {}\n\tusing\
    \ P = Poly<D>;\n\tmap<pii, P> buf;\n\tconst P& get(int l, int r) {\n\t\tif (buf.count(mp(l,\
    \ r))) {\n\t\t\treturn buf[mp(l, r)];\n\t\t}\n\t\tif (r - l == 1) {\n\t\t\treturn\
    \ buf[mp(l, r)] = P{-xs[l], 1};\n\t\t}\n\t\treturn buf[mp(l, r)] = get(l, (l +\
    \ r) / 2) * get((l + r) / 2, r);\n\t}\n};\n\ntemplate<class D>\nPoly<D> interpolate(const\
    \ V<D>& xs, const V<D>& ys) {\n\tMultiEval<D> U(xs);\n\tauto vd = U.dpol.diff();\n\
    \tauto res = U.eval(vd);\n\tPolyBuf<D> buf(xs);\n\n\tfunction<Poly<D>(int,int)>rec=[&](int\
    \ l, int r) {\n\t\tif (r - l == 1) {\n\t\t\treturn Poly<D>{ys[l] / res[l]};\n\t\
    \t}\n\t\tint m = (l + r) / 2;\n\t\treturn rec(l, m) * buf.get(m, r) + rec(m, r)\
    \ * buf.get(l, m);\n\t};\n\treturn rec(0, xs.size());\n}\n"
  code: "template<class D>\nstruct PolyBuf {\n\tconst V<D> &xs;\n\tPolyBuf(const V<D>&\
    \ xs) : xs(xs) {}\n\tusing P = Poly<D>;\n\tmap<pii, P> buf;\n\tconst P& get(int\
    \ l, int r) {\n\t\tif (buf.count(mp(l, r))) {\n\t\t\treturn buf[mp(l, r)];\n\t\
    \t}\n\t\tif (r - l == 1) {\n\t\t\treturn buf[mp(l, r)] = P{-xs[l], 1};\n\t\t}\n\
    \t\treturn buf[mp(l, r)] = get(l, (l + r) / 2) * get((l + r) / 2, r);\n\t}\n};\n\
    \ntemplate<class D>\nPoly<D> interpolate(const V<D>& xs, const V<D>& ys) {\n\t\
    MultiEval<D> U(xs);\n\tauto vd = U.dpol.diff();\n\tauto res = U.eval(vd);\n\t\
    PolyBuf<D> buf(xs);\n\n\tfunction<Poly<D>(int,int)>rec=[&](int l, int r) {\n\t\
    \tif (r - l == 1) {\n\t\t\treturn Poly<D>{ys[l] / res[l]};\n\t\t}\n\t\tint m =\
    \ (l + r) / 2;\n\t\treturn rec(l, m) * buf.get(m, r) + rec(m, r) * buf.get(l,\
    \ m);\n\t};\n\treturn rec(0, xs.size());\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/interpolation.hpp
  requiredBy: []
  timestamp: '2020-09-17 02:07:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/interpolation.hpp
layout: document
redirect_from:
- /library/cpp_src/math/interpolation.hpp
- /library/cpp_src/math/interpolation.hpp.html
title: cpp_src/math/interpolation.hpp
---
