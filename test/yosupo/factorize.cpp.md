---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://miller-rabin.appspot.com/
    - https://joisino.hatenablog.com/entry/2017/08/03/210000
    - https://misteer.hatenablog.com/entry/miller-rabin
    - https://yukicoder.me/problems/no/3030
  bundledCode: "#line 1 \"test/yosupo/factorize.cpp\"\n//#pragma GCC optimize(\"Ofast\"\
    )\n//#pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing uint = unsigned int;\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\n\
    template <class T>\nusing VV = V<V<T>>;\n\ntemplate <class T>\nV<T> make_vec(size_t\
    \ a) {\n    return V<T>(a);\n}\n\ntemplate <class T, class... Ts>\nauto make_vec(size_t\
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
    \ res(v.size());\n    iota(res.begin(), res.end(), 0);\n    sort(res.begin(),\
    \ res.end(), [&](int i, int j) { return v[i] < v[j]; });\n    return res;\n}\n\
    \ntemplate <class T, class U>\nistream& operator>>(istream& is, pair<T, U>& p)\
    \ {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for (auto& x : v)\
    \ {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n    }\n    os\
    \ << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl;\
    \ }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head H, Tail...\
    \ T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\
    \n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n\ntemplate <class\
    \ T, class U>\nT powmod(T x, U k, T m) {\n    x %= m;\n    T res = 1 % m;\n  \
    \  while (k) {\n        if (k & 1) {\n            res = res * x % m;\n       \
    \ }\n        k >>= 1;\n        x = x * x % m;\n    }\n    return res;\n}\n\n//\
    \ see : https://joisino.hatenablog.com/entry/2017/08/03/210000\n// see : https://misteer.hatenablog.com/entry/miller-rabin\n\
    // test : https://yukicoder.me/problems/no/3030\n// ref : http://miller-rabin.appspot.com/\n\
    // check if n is prime\n// n < 4,759,123,141 -> call miller_rabin\n// 2^64 > n\
    \ >= 4,759,123,141 -> call miller_rabin_big\n// O(k log^3 n)\n\nbool miller_rabin(ll\
    \ n) {\n    static const vector<ll> v = {2, 7, 61};\n    if (n < 2) {\n      \
    \  return false;\n    } else if (n == 2) {\n        return true;\n    } else if\
    \ (n % 2 == 0) {\n        return false;\n    }\n\n    ull d = n - 1;\n    int\
    \ s = 0;\n    while (d % 2 == 0) {\n        d /= 2;\n        s++;\n    }\n   \
    \ for (auto a : v) {\n        if (a % n == 0) continue;\n        auto x = powmod(a,\
    \ d, n);\n        if (x == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n\
    \            auto y = x * x % n;\n            if (y == 1) {\n                if\
    \ (x != 1 && x != n - 1) {\n                    return false;\n              \
    \  } else {\n                    x = 1;\n                    break;\n        \
    \        }\n            }\n            x = y;\n        }\n        if (x != 1)\
    \ return false;\n    }\n    return true;\n}\n\nusing R = __int128_t;\nusing ull\
    \ = unsigned long long;\nbool miller_rabin_big(ull n) {\n    static const vector<R>\
    \ v = {2,      325,     9375,      28178,\n                                450775,\
    \ 9780504, 1795265022};\n\n    if (n < 2) {\n        return false;\n    } else\
    \ if (n == 2) {\n        return true;\n    } else if (n % 2 == 0) {\n        return\
    \ false;\n    }\n\n    ull d = n - 1;\n    int s = 0;\n    while (d % 2 == 0)\
    \ {\n        d /= 2;\n        s++;\n    }\n    for (auto a : v) {\n        if\
    \ (a % n == 0) continue;\n        auto x = powmod(a, d, R(n));\n        if (x\
    \ == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n            auto y = x\
    \ * x % n;\n            if (y == 1) {\n                if (x != 1 && x != n -\
    \ 1) {\n                    return false;\n                } else {\n        \
    \            x = 1;\n                    break;\n                }\n         \
    \   }\n            x = y;\n        }\n        if (x != 1) return false;\n    }\n\
    \    return true;\n}\n\n// bit op\nint popcnt(uint x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ull x) { return __builtin_popcountll(x); }\nint bsr(uint x) {\
    \ return 31 - __builtin_clz(x); }\nint bsr(ull x) { return 63 - __builtin_clzll(x);\
    \ }\nint bsf(uint x) { return __builtin_ctz(x); }\nint bsf(ull x) { return __builtin_ctzll(x);\
    \ }\n\n// binary gcd\nll binary_gcd(ll _a, ll _b) {\n    ull a = abs(_a), b =\
    \ abs(_b);\n    if (a == 0) return b;\n    if (b == 0) return a;\n    int shift\
    \ = bsf(a | b);\n    a >>= bsf(a);\n    do {\n        b >>= bsf(b);\n        if\
    \ (a > b) swap(a, b);\n        b -= a;\n    } while (b);\n    return (a << shift);\n\
    }\n\nusing R = __int128;\n\nll pollrard_single(ll n) {\n    auto f = [&](ll x)\
    \ { return ((R)x * x + 1) % n; };\n    if (miller_rabin_big(n)) return n;\n  \
    \  if (n % 2 == 0) return 2;\n    ll st = 0;\n    while (true) {\n        st++;\n\
    \n        ll x = st, y = f(x);\n        while (true) {\n            ll p = gcd((y\
    \ - x + n), n);\n            if (p == 0 || p == n) break;\n            if (p !=\
    \ 1) return p;\n            x = f(x);\n            y = f(f(y));\n        }\n \
    \   }\n}\n\nV<ll> pollrard(ll n) {\n    if (n == 1) return {};\n    ll x = pollrard_single(n);\n\
    \    if (x == n) return {x};\n    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n\
    \    v1.insert(v1.end(), ALL(v2));\n    return v1;\n}\n\nvoid slv() {\n    ll\
    \ x;\n    cin >> x;\n    auto ans = pollrard(x);\n    sort(ALL(ans));\n    debug(x,\
    \ ans);\n    print(SZ(ans), 2);\n    print(ans);\n}\n\nint main() {\n    int cases\
    \ = 1;\n    cin >> cases;\n    rep(i, cases) slv();\n\n    return 0;\n}\n"
  code: "//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing uint = unsigned int;\n\
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
    \ res(v.size());\n    iota(res.begin(), res.end(), 0);\n    sort(res.begin(),\
    \ res.end(), [&](int i, int j) { return v[i] < v[j]; });\n    return res;\n}\n\
    \ntemplate <class T, class U>\nistream& operator>>(istream& is, pair<T, U>& p)\
    \ {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for (auto& x : v)\
    \ {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\";\n    rep(i,\
    \ v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n    }\n    os\
    \ << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out() { cerr << endl;\
    \ }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head H, Tail...\
    \ T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...) \\\
    \n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\ntemplate <class\
    \ T>\nvoid scan(vector<T>& v, T offset = T(0)) {\n    for (auto& x : v) {\n  \
    \      cin >> x;\n        x += offset;\n    }\n}\n\ntemplate <class T>\nvoid print(T\
    \ x, int suc = 1) {\n    cout << x;\n    if (suc == 1)\n        cout << \"\\n\"\
    ;\n    else if (suc == 2)\n        cout << \" \";\n}\n\ntemplate <class T>\nvoid\
    \ print(const vector<T>& v, int suc = 1) {\n    for (int i = 0; i < v.size();\
    \ ++i)\n        print(v[i], i == int(v.size()) - 1 ? suc : 2);\n}\n\nstruct prepare_io\
    \ {\n    prepare_io() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n    }\n} prep_io;\n\ntemplate <class\
    \ T, class U>\nT powmod(T x, U k, T m) {\n    x %= m;\n    T res = 1 % m;\n  \
    \  while (k) {\n        if (k & 1) {\n            res = res * x % m;\n       \
    \ }\n        k >>= 1;\n        x = x * x % m;\n    }\n    return res;\n}\n\n//\
    \ see : https://joisino.hatenablog.com/entry/2017/08/03/210000\n// see : https://misteer.hatenablog.com/entry/miller-rabin\n\
    // test : https://yukicoder.me/problems/no/3030\n// ref : http://miller-rabin.appspot.com/\n\
    // check if n is prime\n// n < 4,759,123,141 -> call miller_rabin\n// 2^64 > n\
    \ >= 4,759,123,141 -> call miller_rabin_big\n// O(k log^3 n)\n\nbool miller_rabin(ll\
    \ n) {\n    static const vector<ll> v = {2, 7, 61};\n    if (n < 2) {\n      \
    \  return false;\n    } else if (n == 2) {\n        return true;\n    } else if\
    \ (n % 2 == 0) {\n        return false;\n    }\n\n    ull d = n - 1;\n    int\
    \ s = 0;\n    while (d % 2 == 0) {\n        d /= 2;\n        s++;\n    }\n   \
    \ for (auto a : v) {\n        if (a % n == 0) continue;\n        auto x = powmod(a,\
    \ d, n);\n        if (x == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n\
    \            auto y = x * x % n;\n            if (y == 1) {\n                if\
    \ (x != 1 && x != n - 1) {\n                    return false;\n              \
    \  } else {\n                    x = 1;\n                    break;\n        \
    \        }\n            }\n            x = y;\n        }\n        if (x != 1)\
    \ return false;\n    }\n    return true;\n}\n\nusing R = __int128_t;\nusing ull\
    \ = unsigned long long;\nbool miller_rabin_big(ull n) {\n    static const vector<R>\
    \ v = {2,      325,     9375,      28178,\n                                450775,\
    \ 9780504, 1795265022};\n\n    if (n < 2) {\n        return false;\n    } else\
    \ if (n == 2) {\n        return true;\n    } else if (n % 2 == 0) {\n        return\
    \ false;\n    }\n\n    ull d = n - 1;\n    int s = 0;\n    while (d % 2 == 0)\
    \ {\n        d /= 2;\n        s++;\n    }\n    for (auto a : v) {\n        if\
    \ (a % n == 0) continue;\n        auto x = powmod(a, d, R(n));\n        if (x\
    \ == 1 || x == n - 1) continue;\n\n        rep(r, s) {\n            auto y = x\
    \ * x % n;\n            if (y == 1) {\n                if (x != 1 && x != n -\
    \ 1) {\n                    return false;\n                } else {\n        \
    \            x = 1;\n                    break;\n                }\n         \
    \   }\n            x = y;\n        }\n        if (x != 1) return false;\n    }\n\
    \    return true;\n}\n\n// bit op\nint popcnt(uint x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ull x) { return __builtin_popcountll(x); }\nint bsr(uint x) {\
    \ return 31 - __builtin_clz(x); }\nint bsr(ull x) { return 63 - __builtin_clzll(x);\
    \ }\nint bsf(uint x) { return __builtin_ctz(x); }\nint bsf(ull x) { return __builtin_ctzll(x);\
    \ }\n\n// binary gcd\nll binary_gcd(ll _a, ll _b) {\n    ull a = abs(_a), b =\
    \ abs(_b);\n    if (a == 0) return b;\n    if (b == 0) return a;\n    int shift\
    \ = bsf(a | b);\n    a >>= bsf(a);\n    do {\n        b >>= bsf(b);\n        if\
    \ (a > b) swap(a, b);\n        b -= a;\n    } while (b);\n    return (a << shift);\n\
    }\n\nusing R = __int128;\n\nll pollrard_single(ll n) {\n    auto f = [&](ll x)\
    \ { return ((R)x * x + 1) % n; };\n    if (miller_rabin_big(n)) return n;\n  \
    \  if (n % 2 == 0) return 2;\n    ll st = 0;\n    while (true) {\n        st++;\n\
    \n        ll x = st, y = f(x);\n        while (true) {\n            ll p = gcd((y\
    \ - x + n), n);\n            if (p == 0 || p == n) break;\n            if (p !=\
    \ 1) return p;\n            x = f(x);\n            y = f(f(y));\n        }\n \
    \   }\n}\n\nV<ll> pollrard(ll n) {\n    if (n == 1) return {};\n    ll x = pollrard_single(n);\n\
    \    if (x == n) return {x};\n    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);\n\
    \    v1.insert(v1.end(), ALL(v2));\n    return v1;\n}\n\nvoid slv() {\n    ll\
    \ x;\n    cin >> x;\n    auto ans = pollrard(x);\n    sort(ALL(ans));\n    debug(x,\
    \ ans);\n    print(SZ(ans), 2);\n    print(ans);\n}\n\nint main() {\n    int cases\
    \ = 1;\n    cin >> cases;\n    rep(i, cases) slv();\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo/factorize.cpp
  requiredBy: []
  timestamp: '2022-03-17 11:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/factorize.cpp
layout: document
redirect_from:
- /library/test/yosupo/factorize.cpp
- /library/test/yosupo/factorize.cpp.html
title: test/yosupo/factorize.cpp
---
