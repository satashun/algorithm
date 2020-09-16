---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp_src/data_structure/fenwick.hpp
    title: cpp_src/data_structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate<class\
    \ T> using V = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\n\n#define pb\
    \ push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n) for(int i=m;i<(n);i++)\n\
    #define ALL(c) (c).begin(),(c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr <<\
    \ __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else \n#define dump(x) true\n\
    #endif\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n\
    template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }\n\
    template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }\n\
    \ntemplate<class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n\tos<<\"(\"<<p.first<<\",\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n\tos<<\"{\";\n\t\
    rep(i, v.size()) {\n\t\tif (i) os<<\",\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\t\
    return os;\n}\n\n#define call_from_test\n#line 1 \"cpp_src/data_structure/fenwick.hpp\"\
    \ntemplate<class T>\nstruct BIT {\n\tint n;\n\tvector<T> bit;\n\n\tBIT(int _n\
    \ = 0) : n(_n), bit(n + 1) {}\n\n\t//sum of [0, i), 0 <= i <= n\n\tT sum(int i)\
    \ {\n\t\tT s = 0;\n\t\twhile (i > 0) {\n\t\t\ts += bit[i];\n\t\t\ti -= i & -i;\n\
    \t\t}\n\t\treturn s;\n\t}\n\n\t//0 <= i < n\n\tvoid add(int i, T x) {\n\t\t++i;\n\
    \t\twhile (i <= n) {\n\t\t\tbit[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\t\
    //[l, r) 0 <= l < r < n\n\tT sum(int l, int r) {\n\t\treturn sum(r) - sum(l);\n\
    \t}\n\n\t//not verified\n\n\t//smallest i, sum(i) >= w, none -> n + 1\n\tint lower_bound(T\
    \ w) {\n\t\tif (w <= 0) return 0;\n\t\tint x = 0, l = 1;\n\t\twhile (l * 2 <=\
    \ n) l *= 2;\n\n\t\tfor (int k = l; k > 0; k /= 2) {\n\t\t\tif (x + k <= n &&\
    \ bit[x + k] < w) {\n\t\t\t\tw -= bit[x + k];\n\t\t\t\tx += k;\n\t\t\t}\n\t\t\
    }\n\t\treturn x + 1;\n\t}\n};\n#line 49 \"test/yosupo/point_add_range_sum.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n\tint N, Q; scanf(\"%d %d\", &N, &Q);\n\
    \tBIT<ll> T(N);\n\tV<ll> a(N);\n\trep(i, N) {\n\t\tscanf(\"%lld\", &a[i]);\n\t\
    \tT.add(i, a[i]);\n\t}\n\twhile (Q--) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\
    \tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tscanf(\"%d %d\", &p, &x);\n\t\t\tT.add(p,\
    \ x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tscanf(\"%d %d\", &l, &r);\n\t\t\t\
    printf(\"%lld\\n\", T.sum(l, r));\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ pii = pair<int, int>;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
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
    #include \"../../cpp_src/data_structure/fenwick.hpp\"\n#undef call_from_test\n\
    \nint main() {\n\tint N, Q; scanf(\"%d %d\", &N, &Q);\n\tBIT<ll> T(N);\n\tV<ll>\
    \ a(N);\n\trep(i, N) {\n\t\tscanf(\"%lld\", &a[i]);\n\t\tT.add(i, a[i]);\n\t}\n\
    \twhile (Q--) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\t\
    int p, x;\n\t\t\tscanf(\"%d %d\", &p, &x);\n\t\t\tT.add(p, x);\n\t\t} else {\n\
    \t\t\tint l, r;\n\t\t\tscanf(\"%d %d\", &l, &r);\n\t\t\tprintf(\"%lld\\n\", T.sum(l,\
    \ r));\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - cpp_src/data_structure/fenwick.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 02:07:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.test.cpp
- /verify/test/yosupo/point_add_range_sum.test.cpp.html
title: test/yosupo/point_add_range_sum.test.cpp
---
