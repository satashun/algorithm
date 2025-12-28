---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/data_structure/FenwickTree.hpp
    title: cpp_src/data_structure/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <algorithm>\n\
    #include <array>\n#include <atomic>\n#include <bitset>\n#include <chrono>\n#include\
    \ <complex>\n#include <condition_variable>\n#include <deque>\n#include <exception>\n\
    #include <forward_list>\n#include <fstream>\n#include <functional>\n#include <future>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include\
    \ <mutex>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <system_error>\n#include <thread>\n\
    #include <tuple>\n#include <type_traits>\n#include <typeindex>\n#include <typeinfo>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate\
    \ <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x <<\
    \ \" = \" << (x) << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll\
    \ TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T,\
    \ class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#define call_from_test\n\
    #line 1 \"cpp_src/data_structure/FenwickTree.hpp\"\ntemplate <class T>\nstruct\
    \ BIT {\n    int n;\n    vector<T> bit;\n\n    BIT(int _n = 0) : n(_n), bit(n\
    \ + 1) {}\n\n    // ABC368G\n    BIT(const V<T>& vec) : n(SZ(vec)), bit(n + 1)\
    \ {\n        rep(i, n) bit[i + 1] = vec[i];\n        for (int i = 1; i <= n; ++i)\
    \ {\n            int j = i + (i & -i);\n            if (j <= n) {\n          \
    \      bit[j] += bit[i];\n            }\n        }\n    }\n\n    // sum of [0,\
    \ i), 0 <= i <= n\n    T sum(int i) {\n        T s = 0;\n        while (i > 0)\
    \ {\n            s += bit[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n\n    // 0 <= i < n\n    void add(int i, T x) {\n        ++i;\n \
    \       while (i <= n) {\n            bit[i] += x;\n            i += i & -i;\n\
    \        }\n    }\n\n    //[l, r) 0 <= l < r < n\n    T sum(int l, int r) { return\
    \ sum(r) - sum(l); }\n\n    // ABC392F, ARC197C\n    // smallest i, sum(i) >=\
    \ w, none -> n + 1\n    int lower_bound(T w) {\n        if (w <= 0) return 0;\n\
    \        int x = 0, l = 1;\n        while (l * 2 <= n) l *= 2;\n\n        for\
    \ (int k = l; k > 0; k /= 2) {\n            if (x + k <= n && bit[x + k] < w)\
    \ {\n                w -= bit[x + k];\n                x += k;\n            }\n\
    \        }\n        return x + 1;\n    }\n\n    // ABC380G\n    V<T> recover()\
    \ {\n        V<T> res(n);\n        rep(i, n) res[i] = sum(i, i + 1);\n       \
    \ return res;\n    }\n};\n#line 107 \"test/yosupo/point_add_range_sum.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, Q;\n    scanf(\"%d %d\", &N,\
    \ &Q);\n    BIT<ll> T(N);\n    V<ll> a(N);\n    rep(i, N) {\n        scanf(\"\
    %lld\", &a[i]);\n        T.add(i, a[i]);\n    }\n    while (Q--) {\n        int\
    \ t;\n        scanf(\"%d\", &t);\n        if (t == 0) {\n            int p, x;\n\
    \            scanf(\"%d %d\", &p, &x);\n            T.add(p, x);\n        } else\
    \ {\n            int l, r;\n            scanf(\"%d %d\", &l, &r);\n          \
    \  printf(\"%lld\\n\", T.sum(l, r));\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <algorithm>\n#include <array>\n#include <atomic>\n#include <bitset>\n\
    #include <chrono>\n#include <complex>\n#include <condition_variable>\n#include\
    \ <deque>\n#include <exception>\n#include <forward_list>\n#include <fstream>\n\
    #include <functional>\n#include <future>\n#include <initializer_list>\n#include\
    \ <iomanip>\n#include <ios>\n#include <iosfwd>\n#include <iostream>\n#include\
    \ <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n#include\
    \ <locale>\n#include <map>\n#include <memory>\n#include <mutex>\n#include <new>\n\
    #include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <ratio>\n#include <regex>\n#include <scoped_allocator>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <stdexcept>\n#include <streambuf>\n\
    #include <string>\n#include <system_error>\n#include <thread>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeindex>\n#include <typeinfo>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <valarray>\n#include <vector>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate\
    \ <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi\
    \ first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m,\
    \ n) for (int i = m; i < (n); i++)\n#define ALL(c) (c).begin(), (c).end()\n\n\
    #ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x)\
    \ << endl\n#else\n#define dump(x) true\n#endif\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\"\
    ;\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#define call_from_test\n#include\
    \ \"../../cpp_src/data_structure/FenwickTree.hpp\"\n#undef call_from_test\n\n\
    int main() {\n    int N, Q;\n    scanf(\"%d %d\", &N, &Q);\n    BIT<ll> T(N);\n\
    \    V<ll> a(N);\n    rep(i, N) {\n        scanf(\"%lld\", &a[i]);\n        T.add(i,\
    \ a[i]);\n    }\n    while (Q--) {\n        int t;\n        scanf(\"%d\", &t);\n\
    \        if (t == 0) {\n            int p, x;\n            scanf(\"%d %d\", &p,\
    \ &x);\n            T.add(p, x);\n        } else {\n            int l, r;\n  \
    \          scanf(\"%d %d\", &l, &r);\n            printf(\"%lld\\n\", T.sum(l,\
    \ r));\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - cpp_src/data_structure/FenwickTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.test.cpp
- /verify/test/yosupo/point_add_range_sum.test.cpp.html
title: test/yosupo/point_add_range_sum.test.cpp
---
