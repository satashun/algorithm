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
  bundledCode: "#line 1 \"cpp_src/other/BaseK.cpp\"\n// modified tute's: https:atcoder.jp/contests/abc380/submissions/59844687\n\
    \nV<ll> pw_base{1};\n\ntemplate <ll base, ll sz>\nstruct Bits {\n    vector<ll>\
    \ data;\n    ll value;\n    Bits() { data.assign(sz, 0); };\n    Bits(ll k) :\
    \ value(k) {\n        data.assign(sz, 0);\n        build(k);\n    }\n    void\
    \ build(ll k) {\n        for (ll i = 0; i < sz; i++) {\n            data[i] =\
    \ k % base;\n            k /= base;\n        }\n    }\n    void set(int k, int\
    \ v) {\n        value += pw_base[k] * (v - data[k]);\n        data[k] = v;\n \
    \   }\n\n    // don't change data and val\n    ll set_val(int k, int v) { return\
    \ value + pw_base[k] * (v - data[k]); }\n\n    Bits& operator=(const ll k) {\n\
    \        fill(ALL(this->data), 0);\n        this->build(k);\n    }\n    ll& operator[](const\
    \ ll k) { return data[k]; }\n    static ll pow(ll k) {\n        ll ret = 1;\n\
    \        while (k--) ret *= base;\n        return ret;\n    }\n    void print()\
    \ {\n        for (ll i = sz - 1; i >= 0; i--) {\n            if (i != sz - 1)\
    \ cout << \" \";\n            cout << data[i];\n        }\n        cout << endl;\n\
    \    }\n};\n\n// using bits = Bits<3, 14>;\n"
  code: "// modified tute's: https:atcoder.jp/contests/abc380/submissions/59844687\n\
    \nV<ll> pw_base{1};\n\ntemplate <ll base, ll sz>\nstruct Bits {\n    vector<ll>\
    \ data;\n    ll value;\n    Bits() { data.assign(sz, 0); };\n    Bits(ll k) :\
    \ value(k) {\n        data.assign(sz, 0);\n        build(k);\n    }\n    void\
    \ build(ll k) {\n        for (ll i = 0; i < sz; i++) {\n            data[i] =\
    \ k % base;\n            k /= base;\n        }\n    }\n    void set(int k, int\
    \ v) {\n        value += pw_base[k] * (v - data[k]);\n        data[k] = v;\n \
    \   }\n\n    // don't change data and val\n    ll set_val(int k, int v) { return\
    \ value + pw_base[k] * (v - data[k]); }\n\n    Bits& operator=(const ll k) {\n\
    \        fill(ALL(this->data), 0);\n        this->build(k);\n    }\n    ll& operator[](const\
    \ ll k) { return data[k]; }\n    static ll pow(ll k) {\n        ll ret = 1;\n\
    \        while (k--) ret *= base;\n        return ret;\n    }\n    void print()\
    \ {\n        for (ll i = sz - 1; i >= 0; i--) {\n            if (i != sz - 1)\
    \ cout << \" \";\n            cout << data[i];\n        }\n        cout << endl;\n\
    \    }\n};\n\n// using bits = Bits<3, 14>;"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/BaseK.cpp
  requiredBy: []
  timestamp: '2025-12-28 17:44:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/BaseK.cpp
layout: document
redirect_from:
- /library/cpp_src/other/BaseK.cpp
- /library/cpp_src/other/BaseK.cpp.html
title: cpp_src/other/BaseK.cpp
---
