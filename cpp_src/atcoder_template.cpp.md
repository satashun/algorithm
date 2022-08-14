---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/atcoder_template.cpp\"\n#pragma region satashun\n\
    //#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\n\n#include <atcoder/modint>\nusing namespace std;\n\
    using namespace atcoder;\n\nusing uint = unsigned int;\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing pii = pair<int, int>;\nusing Mint = modint998244353;\n\
    \ntemplate <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\
    \ntemplate <class T>\nV<T> make_vec(size_t a) {\n    return V<T>(a);\n}\n\ntemplate\
    \ <class T, class... Ts>\nauto make_vec(size_t a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a,\
    \ make_vec<T>(ts...));\n}\n\ntemplate <typename T, typename V>\nvoid fill_vec(vector<T>&\
    \ vec, const V& val, int len) {\n    vec.assign(len, val);\n}\ntemplate <typename\
    \ T, typename V, typename... Ts>\nvoid fill_vec(vector<T>& vec, const V& val,\
    \ int len, Ts... ts) {\n    vec.resize(len),\n        for_each(begin(vec), end(vec),\
    \ [&](T& v) { fill_vec(v, val, ts...); });\n}\n\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mp make_pair\n#define fi first\n#define se second\n\
    #define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n);\
    \ i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b)\
    \ - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(), (c).end()\n#define SZ(x)\
    \ ((int)(x).size())\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n\
    \ - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T& t, const U& u) {\n   \
    \ if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid chmax(T& t, const U&\
    \ u) {\n    if (t < u) t = u;\n}\n\ntemplate <typename T>\nint arglb(const V<T>&\
    \ v, const T& x) {\n    return distance(v.begin(), lower_bound(ALL(v), x));\n\
    }\n\ntemplate <typename T>\nint argub(const V<T>& v, const T& x) {\n    return\
    \ distance(v.begin(), upper_bound(ALL(v), x));\n}\n\ntemplate <class T>\nvoid\
    \ mkuni(vector<T>& v) {\n    sort(ALL(v));\n    v.erase(unique(ALL(v)), end(v));\n\
    }\n\ntemplate <class T>\nvector<int> sort_by(const vector<T>& v, bool increasing\
    \ = true) {\n    vector<int> res(v.size());\n    iota(res.begin(), res.end(),\
    \ 0);\n\n    if (increasing) {\n        stable_sort(res.begin(), res.end(),\n\
    \                    [&](int i, int j) { return v[i] < v[j]; });\n    } else {\n\
    \        stable_sort(res.begin(), res.end(),\n                    [&](int i, int\
    \ j) { return v[i] > v[j]; });\n    }\n    return res;\n}\n\ntemplate <class T,\
    \ class U>\nistream& operator>>(istream& is, pair<T, U>& p) {\n    is >> p.first\
    \ >> p.second;\n    return is;\n}\n\ntemplate <class T, class U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << \"(\" << p.first << \",\" << p.second\
    \ << \")\";\n    return os;\n}\n\ntemplate <class T>\nistream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (auto& x : v) {\n        is >> x;\n    }\n    return\
    \ is;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const set<T>& ST) {\n    os << \"{\";\n\
    \    for (auto it = ST.begin(); it != ST.end(); ++it) {\n        if (it != ST.begin())\
    \ os << \",\";\n        os << *it;\n    }\n    os << \"}\";\n    return os;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const map<T,\
    \ U>& MP) {\n    for (auto it = MP.begin(); it != MP.end(); ++it) {\n        os\
    \ << \"(\" << it->first << \": \" << it->second << \")\";\n    }\n    return os;\n\
    }\n\ntemplate <class T>\nauto operator<<(ostream& os, T t) ->\n    typename std::enable_if_t<internal::is_modint<T>::value,\
    \ ostream&> {\n    os << t.val();\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nV<T>& operator+=(V<T>& vec, const T& v) {\n    for (auto& x : vec) x +=\
    \ v;\n    return vec;\n}\n\ntemplate <class T>\nV<T>& operator-=(V<T>& vec, const\
    \ T& v) {\n    for (auto& x : vec) x -= v;\n    return vec;\n}\n\n// suc : 1 =\
    \ newline, 2 = space\ntemplate <class T>\nvoid print(T x, int suc = 1) {\n   \
    \ cout << x;\n    if (suc == 1)\n        cout << \"\\n\";\n    else if (suc ==\
    \ 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid print(const vector<T>&\
    \ v, int suc = 1) {\n    for (int i = 0; i < v.size(); ++i)\n        print(v[i],\
    \ i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate <class T>\nvoid show(T x)\
    \ {\n    print(x, 1);\n}\n\ntemplate <typename Head, typename... Tail>\nvoid show(Head\
    \ H, Tail... T) {\n    print(H, 2);\n    show(T...);\n}\n\nint topbit(int t) {\
    \ return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(ll t) { return t ==\
    \ 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(int a) { return a == 0 ? 32\
    \ : __builtin_ctz(a); }\nint botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a);\
    \ }\nint popcount(int t) { return __builtin_popcount(t); }\nint popcount(ll t)\
    \ { return __builtin_popcountll(t); }\nint bit_parity(int t) { return __builtin_parity(t);\
    \ }\nint bit_parity(ll t) { return __builtin_parityll(t); }\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n#pragma endregion\
    \ satashun\n\nint main() {\n    return 0;\n}\n"
  code: "#pragma region satashun\n//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\n#include <atcoder/modint>\n\
    using namespace std;\nusing namespace atcoder;\n\nusing uint = unsigned int;\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing pii = pair<int,\
    \ int>;\nusing Mint = modint998244353;\n\ntemplate <class T>\nusing V = vector<T>;\n\
    template <class T>\nusing VV = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t\
    \ a) {\n    return V<T>(a);\n}\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t\
    \ a, Ts... ts) {\n    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));\n\
    }\n\ntemplate <typename T, typename V>\nvoid fill_vec(vector<T>& vec, const V&\
    \ val, int len) {\n    vec.assign(len, val);\n}\ntemplate <typename T, typename\
    \ V, typename... Ts>\nvoid fill_vec(vector<T>& vec, const V& val, int len, Ts...\
    \ ts) {\n    vec.resize(len),\n        for_each(begin(vec), end(vec), [&](T& v)\
    \ { fill_vec(v, val, ts...); });\n}\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define per(i, b)\
    \ per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n\
    #define ALL(c) (c).begin(), (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class\
    \ T, class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <typename T>\nint arglb(const V<T>& v, const T& x) {\n    return\
    \ distance(v.begin(), lower_bound(ALL(v), x));\n}\n\ntemplate <typename T>\nint\
    \ argub(const V<T>& v, const T& x) {\n    return distance(v.begin(), upper_bound(ALL(v),\
    \ x));\n}\n\ntemplate <class T>\nvoid mkuni(vector<T>& v) {\n    sort(ALL(v));\n\
    \    v.erase(unique(ALL(v)), end(v));\n}\n\ntemplate <class T>\nvector<int> sort_by(const\
    \ vector<T>& v, bool increasing = true) {\n    vector<int> res(v.size());\n  \
    \  iota(res.begin(), res.end(), 0);\n\n    if (increasing) {\n        stable_sort(res.begin(),\
    \ res.end(),\n                    [&](int i, int j) { return v[i] < v[j]; });\n\
    \    } else {\n        stable_sort(res.begin(), res.end(),\n                 \
    \   [&](int i, int j) { return v[i] > v[j]; });\n    }\n    return res;\n}\n\n\
    template <class T, class U>\nistream& operator>>(istream& is, pair<T, U>& p) {\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for (auto& x : v)\
    \ {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n    }\n    os\
    \ << \"}\";\n    return os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream&\
    \ os, const set<T>& ST) {\n    os << \"{\";\n    for (auto it = ST.begin(); it\
    \ != ST.end(); ++it) {\n        if (it != ST.begin()) os << \",\";\n        os\
    \ << *it;\n    }\n    os << \"}\";\n    return os;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const map<T, U>& MP) {\n    for (auto it\
    \ = MP.begin(); it != MP.end(); ++it) {\n        os << \"(\" << it->first << \"\
    : \" << it->second << \")\";\n    }\n    return os;\n}\n\ntemplate <class T>\n\
    auto operator<<(ostream& os, T t) ->\n    typename std::enable_if_t<internal::is_modint<T>::value,\
    \ ostream&> {\n    os << t.val();\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nV<T>& operator+=(V<T>& vec, const T& v) {\n    for (auto& x : vec) x +=\
    \ v;\n    return vec;\n}\n\ntemplate <class T>\nV<T>& operator-=(V<T>& vec, const\
    \ T& v) {\n    for (auto& x : vec) x -= v;\n    return vec;\n}\n\n// suc : 1 =\
    \ newline, 2 = space\ntemplate <class T>\nvoid print(T x, int suc = 1) {\n   \
    \ cout << x;\n    if (suc == 1)\n        cout << \"\\n\";\n    else if (suc ==\
    \ 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid print(const vector<T>&\
    \ v, int suc = 1) {\n    for (int i = 0; i < v.size(); ++i)\n        print(v[i],\
    \ i == int(v.size()) - 1 ? suc : 2);\n}\n\ntemplate <class T>\nvoid show(T x)\
    \ {\n    print(x, 1);\n}\n\ntemplate <typename Head, typename... Tail>\nvoid show(Head\
    \ H, Tail... T) {\n    print(H, 2);\n    show(T...);\n}\n\nint topbit(int t) {\
    \ return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(ll t) { return t ==\
    \ 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(int a) { return a == 0 ? 32\
    \ : __builtin_ctz(a); }\nint botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a);\
    \ }\nint popcount(int t) { return __builtin_popcount(t); }\nint popcount(ll t)\
    \ { return __builtin_popcountll(t); }\nint bit_parity(int t) { return __builtin_parity(t);\
    \ }\nint bit_parity(ll t) { return __builtin_parityll(t); }\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n#pragma endregion\
    \ satashun\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/atcoder_template.cpp
  requiredBy: []
  timestamp: '2022-08-15 00:42:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/atcoder_template.cpp
layout: document
redirect_from:
- /library/cpp_src/atcoder_template.cpp
- /library/cpp_src/atcoder_template.cpp.html
title: cpp_src/atcoder_template.cpp
---
