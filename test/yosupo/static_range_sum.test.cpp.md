---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/data_structure/RangeSum1D.hpp
    title: cpp_src/data_structure/RangeSum1D.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#pragma region satashun\n\
    //#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing uint = unsigned int;\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing pii = pair<int,\
    \ int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV\
    \ = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n\
    }\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n  \
    \  return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n}\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for\
    \ (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T>\n\
    void mkuni(vector<T>& v) {\n    sort(ALL(v));\n    v.erase(unique(ALL(v)), end(v));\n\
    }\n\ntemplate <class T>\nvector<int> sort_by(const vector<T>& v) {\n    vector<int>\
    \ res(v.size());\n    iota(res.begin(), res.end(), 0);\n    stable_sort(res.begin(),\
    \ res.end(),\n                [&](int i, int j) { return v[i] < v[j]; });\n  \
    \  return res;\n}\n\ntemplate <class T, class U>\nistream& operator>>(istream&\
    \ is, pair<T, U>& p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v)\
    \ {\n    for (auto& x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os <<\
    \ \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate\
    \ <class T>\nvoid show(T x) {\n    print(x, 1);\n}\n\ntemplate <typename Head,\
    \ typename... Tail>\nvoid show(Head H, Tail... T) {\n    print(H, 2);\n    show(T...);\n\
    }\n\nstruct prepare_io {\n    prepare_io() {\n        cin.tie(nullptr);\n    \
    \    ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \    }\n} prep_io;\n#pragma endregion satashun\n\n#define call_from_test\n#line\
    \ 1 \"cpp_src/data_structure/RangeSum1D.hpp\"\ntemplate <class T>\nV<T> cumsum(const\
    \ V<T>& vec) {\n    int n = vec.size();\n    V<T> res(n + 1);\n    rep(i, n) {\
    \ res[i + 1] = res[i] + vec[i]; }\n    return res;\n}\n#line 156 \"test/yosupo/static_range_sum.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n \
    \   V<ll> a(N);\n    cin >> a;\n    auto ps = cumsum(a);\n    rep(i, Q) {\n  \
    \      int l, r;\n        cin >> l >> r;\n        show(ps[r] - ps[l]);\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#pragma\
    \ region satashun\n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"\
    unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing uint\
    \ = unsigned int;\nusing ll = long long;\nusing ull = unsigned long long;\nusing\
    \ pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate <class\
    \ T>\nusing VV = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t a) {\n \
    \   return V<T>(a);\n}\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t\
    \ a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n\
    }\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define\
    \ fi first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i,\
    \ m, n) for (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define\
    \ per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T>\n\
    void mkuni(vector<T>& v) {\n    sort(ALL(v));\n    v.erase(unique(ALL(v)), end(v));\n\
    }\n\ntemplate <class T>\nvector<int> sort_by(const vector<T>& v) {\n    vector<int>\
    \ res(v.size());\n    iota(res.begin(), res.end(), 0);\n    stable_sort(res.begin(),\
    \ res.end(),\n                [&](int i, int j) { return v[i] < v[j]; });\n  \
    \  return res;\n}\n\ntemplate <class T, class U>\nistream& operator>>(istream&\
    \ is, pair<T, U>& p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v)\
    \ {\n    for (auto& x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os <<\
    \ \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate\
    \ <class T>\nvoid show(T x) {\n    print(x, 1);\n}\n\ntemplate <typename Head,\
    \ typename... Tail>\nvoid show(Head H, Tail... T) {\n    print(H, 2);\n    show(T...);\n\
    }\n\nstruct prepare_io {\n    prepare_io() {\n        cin.tie(nullptr);\n    \
    \    ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \    }\n} prep_io;\n#pragma endregion satashun\n\n#define call_from_test\n#include\
    \ \"../../cpp_src/data_structure/RangeSum1D.hpp\"\n#undef call_from_test\n\nint\
    \ main() {\n    int N, Q;\n    cin >> N >> Q;\n    V<ll> a(N);\n    cin >> a;\n\
    \    auto ps = cumsum(a);\n    rep(i, Q) {\n        int l, r;\n        cin >>\
    \ l >> r;\n        show(ps[r] - ps[l]);\n    }\n    return 0;\n}"
  dependsOn:
  - cpp_src/data_structure/RangeSum1D.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-05-22 15:10:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_sum.test.cpp
- /verify/test/yosupo/static_range_sum.test.cpp.html
title: test/yosupo/static_range_sum.test.cpp
---
